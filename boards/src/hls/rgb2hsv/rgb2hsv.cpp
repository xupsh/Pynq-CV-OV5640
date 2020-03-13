#include "rgb2hsv.h"

void rgb2hsv(AXI_STREAM& in, AXI_STREAM& out, int rows, int cols) {

#pragma HLS INTERFACE axis port=in
#pragma HLS INTERFACE axis port=out

#pragma HLS INTERFACE s_axilite port=cols
#pragma HLS INTERFACE s_axilite port=rows
#pragma HLS INTERFACE s_axilite port=return

#pragma HLS DATAFLOW

	RGB_IMAGE src(rows, cols);
	RGB_IMAGE dst(rows, cols);

	AXIvideo2Mat(in, src);

	hls::CvtColor<HLS_RGB2HSV>(src, dst);

    Mat2AXIvideo(dst, out);
}
