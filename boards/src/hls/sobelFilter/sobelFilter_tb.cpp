#include "hls_video.h"
#include "hls_opencv.h"
#include "sobelFilter.h"

int main(int argc, char** argv) {
	IplImage* src = cvLoadImage("lena.jpg", 1);
	IplImage* dst_x = cvCreateImage(cvGetSize(src), src->depth, src->nChannels);
	IplImage* dst_y = cvCreateImage(cvGetSize(src), src->depth, src->nChannels);

	AXI_STREAM  src_axi, dst_axi;
	IplImage2AXIvideo(src, src_axi);
	sobelFilter(src_axi, dst_axi, src->height, src->width, 0);
	AXIvideo2IplImage(dst_axi, dst_x);

	IplImage2AXIvideo(src, src_axi);
	sobelFilter(src_axi, dst_axi, src->height, src->width, 1);
	AXIvideo2IplImage(dst_axi, dst_y);

	cvShowImage("src",src);
	cvShowImage("dst_x",dst_x);
	cvShowImage("dst_y",dst_y);
	cvWaitKey(0);

	cvReleaseImage(&src);
	cvReleaseImage(&dst_x);
	cvReleaseImage(&dst_y);

	return 0;
}
