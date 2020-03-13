#include "canny_edge.h"

void gradient_decomposition(GRAY_IMAGE_16S& gx, GRAY_IMAGE_16S& gy, GRAY_IMAGE_16& gd) {

	HLS_SIZE_T rows = gx.rows;
	HLS_SIZE_T cols = gx.cols;

	hls::Scalar<1, short> pixel_gx;
	hls::Scalar<1, short> pixel_gy;
	hls::Scalar<1, unsigned short> element_pixel;
	hls::Scalar<1, unsigned char> dir_pixel;

	short element_gx;
	short element_gy;
	unsigned short abs_gx;
	unsigned short abs_gy;
	unsigned short abs_g;
	unsigned short dir_g;
	unsigned short element_gd;
	// Calculate gradient magnitude and direction
	for( HLS_SIZE_T i = 0; i < rows; i++ ) {
		for( HLS_SIZE_T j = 0; j < cols; j++ ) {
#pragma HLS LOOP_FLATTEN OFF
#pragma HLS DEPENDENCE array inter false
#pragma HLS PIPELINE
		    // Stream in the two input directional gradients
			gx >> pixel_gx;
			gy >> pixel_gy;
			element_gx = pixel_gx.val[0];
			element_gy = pixel_gy.val[0];

			// Calculate the absolute value of the pixel's gradient
			abs_gx = hls::abs(element_gx);
			abs_gy = hls::abs(element_gy);

			// Calculate the magnitude of the gradient (approximated by the L1 norm)
			abs_g  = abs_gx + abs_gy;
			// Calculate the approximate direction of the pixel
			// 0 is 0 degrees, 1 is 45 degrees, 2 is 90 degrees, 3 is 135 degrees
			if (abs_gx > abs_gy && ((element_gx > 0 && element_gy >= 0)||(element_gx < 0 && element_gy <= 0))) {
			  if (5*abs_gx > (12*abs_gy)) dir_g = 0;
			  else dir_g = 1;
			}
			else if (abs_gx <= abs_gy && ((element_gx > 0 && element_gy > 0)||(element_gx < 0 && element_gy < 0))) {
			  if (5*abs_gy > (12*abs_gx)) dir_g = 2;
			  else dir_g = 1;
			}
			else if (abs_gx <= abs_gy && ((element_gx >= 0 && element_gy < 0)||(element_gx <= 0 && element_gy > 0))) {
			  if (5*abs_gy > (12*abs_gx)) dir_g = 2;
			  else dir_g = 3;
			}
			else {
			  if(abs_gx== 0 && abs_gy == 0) dir_g = 0;
			  else if (5*abs_gx > (12*abs_gy)) dir_g = 0;
			  else dir_g = 3;
			}
			// Combine the 8-bit magnitude and directions into a 16 bit pixel (direction in the LSBs)
			element_gd = ( ( abs_g << 2 ) | dir_g );
			element_pixel.val[0] = element_gd;
			// Stream out the pixel
			gd << element_pixel;
		}
	}
}

void nonmax_suppression(GRAY_IMAGE_16& gd, GRAY_IMAGE_16& dst) {

	HLS_SIZE_T rows = gd.rows;
	HLS_SIZE_T cols = gd.cols;

	// Line buffer can only handle images of up to 1920 pixels wide
	hls::LineBuffer<2, 1920, unsigned short> linebuff;
	// 3x3 computation kernel
	hls::Window<3, 3, unsigned short> win;

	hls::Scalar<1, unsigned short> pixel_gd;
	hls::Scalar<1, unsigned short> out_pixel;

	unsigned short element_gd;
	unsigned short out_pixel_val;
	unsigned char current_dir;
	unsigned short current_grad;
	unsigned short ga;
	unsigned short gb;
	unsigned short tmp0;
	unsigned short tmp1;
	for( HLS_SIZE_T i = 0; i < rows+1; i++ ) {
		for( HLS_SIZE_T j = 0; j < cols+1; j++ ) {
#pragma HLS LOOP_FLATTEN OFF
#pragma HLS DEPENDENCE array inter false
#pragma HLS PIPELINE

		  // read pixels from the input stream only if within the bounds of the image
		  if ( i < rows && j < cols ) {
			gd >> pixel_gd;
			element_gd = pixel_gd.val[0];
		  }

		  // Save the values in the line buffer
		  // and then shift up the values in the current column of the linebuffer
		  if( j < cols ) {
			tmp1 = linebuff.getval(1, j);
			tmp0 = linebuff.getval(0, j);
			// shift values up 1 row
			linebuff.val[1][j] = tmp0;
		  }
		  // Insert a new pixel into the bottom right of the line buffer if it is present
		  if( j < cols && i < rows ){
			linebuff.insert_bottom( element_gd, j );
		  }

		  // Shifting the window right
		  win.shift_right();

		  // Copying values from the linebuffer to the window
		  if( j < cols ) {
			win.insert( element_gd, 0, 0 );
			win.insert( tmp0, 1, 0 );
			win.insert( tmp1, 2, 0 );
		  }

		  // separate the 16-bit value into the gradient direction and magnitude
		  current_dir = win.getval(1, 1) & 3;
		  current_grad = win.getval(1, 1) >> 2;

		  // Calculate output by checking if the pixel is a local maximum
		  // Only calculate an output if the entire kernel uses valid pixels
		  if( i <= 1 || j <= 1 || i > rows-1 || j > cols-1 ) {
			out_pixel_val = 0;
		  }
		  else {
			// Checking in the east-west axis
			if ( current_dir == 0/*0*/ ) {
			  ga = win.getval( 1, 0 )>>2;
			  gb = win.getval( 1, 2 )>>2;
			}
			// Checking in the northEast-southWest axis
			else if ( current_dir == 3/*1*/ ){
			  ga = win.getval( 2, 0 )>>2;
			  gb = win.getval( 0, 2 )>>2;
			}
			// Checking in the north-south axis
			else if ( current_dir == 2/*2*/ ){
			  ga = win.getval( 0, 1 )>>2;
			  gb = win.getval( 2, 1 )>>2;
			}
			// Checking in the northWest-southEast axis
			else { // ( current_dir == 1/*3*/ )
			  ga = win.getval( 2, 2 )>>2;
			  gb = win.getval( 0, 0 )>>2;
			}

			// The pixel is an edge only if it is a local maximum along any axis
			if( current_grad > ga && current_grad > gb ) {
			  out_pixel_val = current_grad;
			}
			else {
			  out_pixel_val = 0;
			}
		  }

		  // Output a pixel only if it is part of the actual image
		  if( j > 0 && i > 0 ) {
			out_pixel.val[0] = out_pixel_val;
			dst << out_pixel;
		  }

		}
	}
}

void hysteresis( GRAY_IMAGE_16& src, GRAY_IMAGE& dst, int threshold_low, int threshold_high ) {

	HLS_SIZE_T rows = src.rows;
	HLS_SIZE_T cols = src.cols;

	// Line buffer can only handle images of up to 1920 pixels wide
	hls::LineBuffer<2, 1920, unsigned short> linebuff;
	// 3x3 computation kernel
	hls::Window<3, 3, unsigned short> win;

	hls::Scalar<1, unsigned short> pixel_gd;
	hls::Scalar<1, unsigned char> out_pixel;

	unsigned short element_gd;
	unsigned char out_pixel_val;
	unsigned short tmp0;
	unsigned short tmp1;

	for( HLS_SIZE_T i = 0; i < rows+1; i++ ) {
		for( HLS_SIZE_T j = 0; j < cols+1; j++ ) {
#pragma HLS LOOP_FLATTEN OFF
#pragma HLS DEPENDENCE array inter false
#pragma HLS PIPELINE

		  // read pixels from the input stream only if within the bounds of the image
		  if ( i < rows && j < cols ) {
		    src >> pixel_gd;
			element_gd = pixel_gd.val[0];
		  }

		  // Save the values in the line buffer
		  // and then shift up the values in the current column of the linebuffer
		  if( j < cols ) {
			tmp1 = linebuff.getval(1, j);
			tmp0 = linebuff.getval(0, j);
			// shift values up 1 row
			linebuff.val[1][j] = tmp0;
		  }
		  // Insert a new pixel into the bottom right of the line buffer if it is present
		  if( j < cols && i < rows ){
			linebuff.insert_bottom( element_gd, j );
		  }

		  // Shifting the window right
		  win.shift_right();

		  // Copying values from the linebuffer to the window
		  if( j < cols ) {
			win.insert( element_gd, 0, 0 );
			win.insert( tmp0, 1, 0 );
			win.insert( tmp1, 2, 0 );
		  }

		  // Calculate if this pixel is an edge by comparing it to
		  // the high and low thresholds and its neighbors in the kernel
		  // Only calculate an output if the entire kernel uses valid pixels
		  if( i <= 1 || j <= 1 || i > rows-1 || j > cols-1 ) {
			out_pixel_val = 0;
		  }
		  else {
			if( win.getval(1,1) < threshold_low ){
			  out_pixel_val = 0;
			}
			else if( 	win.getval(1,1) > threshold_high ||
						win.getval(0,0) > threshold_high  ||
						win.getval(0,1) > threshold_high  ||
						win.getval(0,2) > threshold_high  ||
						win.getval(1,0) > threshold_high  ||
						win.getval(1,2) > threshold_high  ||
						win.getval(2,0) > threshold_high  ||
						win.getval(2,1) > threshold_high  ||
						win.getval(2,2) > threshold_high  ) {
			  out_pixel_val = 255;
			}
			else {
			  out_pixel_val = 0;
			}
		  }

		  // Output a pixel only if it is part of the actual image
		  if( j > 0 && i > 0 ) {
			out_pixel.val[0] = out_pixel_val;
			dst << out_pixel;
		  }
		}
	}
}

void canny_edge(AXI_STREAM& in, AXI_STREAM& out, int rows, int cols, int low_threshold, int high_threshold) {

#pragma HLS INTERFACE axis port=in
#pragma HLS INTERFACE axis port=out

#pragma HLS INTERFACE s_axilite port=cols
#pragma HLS INTERFACE s_axilite port=rows

#pragma HLS INTERFACE s_axilite port=low_threshold
#pragma HLS INTERFACE s_axilite port=high_threshold
#pragma HLS INTERFACE s_axilite port=return

#pragma HLS DATAFLOW

	RGB_IMAGE src(rows, cols);
	RGB_IMAGE dst(rows, cols);

	GRAY_IMAGE src_bw(rows, cols);
	GRAY_IMAGE src_blur(rows, cols);
	GRAY_IMAGE src1(rows, cols);
	GRAY_IMAGE src2(rows, cols);
	GRAY_IMAGE_16S sobel_gx(rows, cols);
	GRAY_IMAGE_16S sobel_gy(rows, cols);
    GRAY_IMAGE_16 grad_gd(rows, cols);
    GRAY_IMAGE_16 suppressed(rows, cols);
    GRAY_IMAGE thresholded(rows, cols);
    GRAY_IMAGE canny_edges(rows, cols);

	GRAY_IMAGE gray_img(rows, cols);

	hls::AXIvideo2Mat(in, src);

	hls::CvtColor<HLS_RGB2GRAY, HLS_8UC3, HLS_8UC1>(src, src_bw);

	hls::Duplicate( src_bw, src1, src2 );
	// Calculate gradients in x and y direction using Sobel filter
    hls::Sobel<1,0,3>( src1, sobel_gx );
    hls::Sobel<0,1,3>( src2, sobel_gy );

	// Calculate gradient magnitude and direction
	gradient_decomposition( sobel_gx, sobel_gy, grad_gd );
	// Perform non-maximum suppression for edge thinning
	nonmax_suppression( grad_gd, suppressed );
	// Perform hysteresis thresholding for edge tracing

	hysteresis( suppressed, canny_edges, low_threshold, high_threshold);

	hls::CvtColor<HLS_GRAY2RGB, HLS_8UC1, HLS_8UC3>(canny_edges, dst);


	hls::Mat2AXIvideo(dst, out);
}
