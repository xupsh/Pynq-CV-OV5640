#include "equalizeHist.h"

void equalizeHist(AXI_STREAM& in, AXI_STREAM& out, int rows, int cols) {

#pragma HLS INTERFACE axis port=in
#pragma HLS INTERFACE axis port=out

#pragma HLS INTERFACE s_axilite port=cols
#pragma HLS INTERFACE s_axilite port=rows
#pragma HLS INTERFACE s_axilite port=return

#pragma HLS DATAFLOW

	RGB_IMAGE src(rows, cols);
	RGB_IMAGE dst(rows, cols);

	GRAY_IMAGE gray_img(rows, cols);
	GRAY_IMAGE gray_hist(rows, cols);


	hls::AXIvideo2Mat(in, src);

	hls::CvtColor<HLS_RGB2GRAY, HLS_8UC3, HLS_8UC1>(src, gray_img);
	hls::EqualizeHist(gray_img, gray_hist);
	hls::CvtColor<HLS_GRAY2RGB, HLS_8UC1, HLS_8UC3>(gray_hist, dst);

	hls::Mat2AXIvideo(dst, out);
}
