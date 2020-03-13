#include "hls_video.h"
#include "hls_opencv.h"
#include "equalizeHist.h"

int main(int argc, char** argv) {
	IplImage* src = cvLoadImage("lena.jpg", 1);
	IplImage* dst = cvCreateImage(cvGetSize(src), src->depth, src->nChannels);

	AXI_STREAM  src_axi, dst_axi;
	IplImage2AXIvideo(src, src_axi);
	equalizeHist(src_axi, dst_axi, src->height, src->width);
	AXIvideo2IplImage(dst_axi, dst);

	IplImage2AXIvideo(src, src_axi);
	equalizeHist(src_axi, dst_axi, src->height, src->width);
	AXIvideo2IplImage(dst_axi, dst);

	cvShowImage("src",src);
	cvShowImage("dst",dst);
	cvWaitKey(0);

	cvReleaseImage(&src);
	cvReleaseImage(&dst);

	return 0;
}
