#include "xf_erosion_config.h"

void erosion_accel(xf::Mat<TYPE, HEIGHT, WIDTH, NPC1> &_src,xf::Mat<TYPE, HEIGHT, WIDTH, NPC1> &_dst, unsigned char kernel[FILTER_SIZE*FILTER_SIZE]);

void xf_erosion_accel(hls::stream< ap_axiu<8,1,1,1> >& _src,hls::stream< ap_axiu<8,1,1,1> >& _dst,int height,int width)
{
#pragma HLS INTERFACE s_axilite port=return
#pragma HLS INTERFACE axis register both  port=_src
#pragma HLS INTERFACE axis register both  port=_dst
#pragma HLS INTERFACE s_axilite port=width
#pragma HLS INTERFACE s_axilite port=height

	 xf::Mat<TYPE, HEIGHT, WIDTH, NPC1> imgInput1(height,width);
	 xf::Mat<TYPE, HEIGHT, WIDTH, NPC1> imgOutput1(height,width);

	 unsigned char kernel[FILTER_SIZE*FILTER_SIZE];
	 loop_kernel:for(int i = 0; i < FILTER_SIZE*FILTER_SIZE; ++i)
	 {
#pragma HLS UNROLL
		 kernel[i] = 1;
	 }

#pragma HLS stream variable=imgInput1.data dim=1 depth=1
#pragma HLS stream variable=imgOutput1.data dim=1 depth=1
	#pragma HLS dataflow

	xf::AXIvideo2xfMat(_src, imgInput1);

	erosion_accel(imgInput1,imgOutput1, kernel);

	xf::xfMat2AXIvideo(imgOutput1, _dst);


}
