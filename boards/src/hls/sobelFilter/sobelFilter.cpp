#include "sobelFilter.h"

void Sobel(GRAY_IMAGE& src, GRAY_IMAGE& dst, int order) {
	if(order)
		hls::Sobel<0,1,3>(src, dst);
	else
		hls::Sobel<1,0,3>(src, dst);
}

void sobelFilter(AXI_STREAM& in, AXI_STREAM& out, int rows, int cols, int order = 0) {

#pragma HLS INTERFACE axis port=in
#pragma HLS INTERFACE axis port=out

#pragma HLS INTERFACE s_axilite port=cols
#pragma HLS INTERFACE s_axilite port=rows
#pragma HLS INTERFACE s_axilite port=order
#pragma HLS INTERFACE s_axilite port=return

#pragma HLS DATAFLOW

	RGB_IMAGE src(rows, cols);
	RGB_IMAGE dst(rows, cols);

	GRAY_IMAGE gray_img(rows, cols);
	GRAY_IMAGE sobel_img(rows, cols);


	hls::AXIvideo2Mat(in, src);

	hls::CvtColor<HLS_RGB2GRAY, HLS_8UC3, HLS_8UC1>(src, gray_img);
	Sobel(gray_img, sobel_img, order);
	hls::CvtColor<HLS_GRAY2RGB, HLS_8UC1, HLS_8UC3>(sobel_img, dst);

    Mat2AXIvideo(dst, out);
}
