#include "hls_opencv.h"
#include "rgb2hsv.h"

#define ERROR_THRESHOLD 2

int main(int argc, char** argv) {
	IplImage* src = cvLoadImage("lena.jpg", 1);
	IplImage* dst = cvCreateImage(cvGetSize(src), src->depth, src->nChannels);
	cv::Mat inputimg,outputimg,ocv_outputimg,error_img0;
	AXI_STREAM  src_axi, dst_axi;

	inputimg = src;

	cv::Size S0(cvGetSize(src));
	outputimg.create(S0, CV_8UC3);
	error_img0.create(S0, CV_8UC1);

	cvMat2AXIvideo(inputimg, src_axi);
	rgb2hsv(src_axi, dst_axi, src->height, src->width);
	AXIvideo2cvMat(dst_axi, outputimg);

	cv::cvtColor(inputimg,ocv_outputimg,CV_RGB2HSV);

	cv::absdiff(outputimg,ocv_outputimg,error_img0);

	double minval, maxval;
	float err_per;
	int cnt;

	minval = 255;
	maxval = 0;
	int max_i=0, max_j=0, min_i=0, min_j=0;
	cnt = 0;
	for (int i = 0; i < error_img0.rows; i++) {
		for (int j = 0; j < error_img0.cols; j++) {
			uchar v = error_img0.at<uchar>(i, j);

			if (v > ERROR_THRESHOLD)
				cnt++;
			if (minval > v)
			{
				minval = v;
				min_i = i;
				min_j = j;
			}
			if (maxval < v)
			{
				maxval = v;
				max_i = i;
								max_j = j;
			}
		}
	}
	err_per = 100.0 * (float) cnt / (error_img0.rows * error_img0.cols);
	fprintf(stderr, "Minimum error in intensity = %f (%d, %d)\n"
					"Maximum error in intensity = %f (%d, %d)\n"
					"Percentage of pixels above error threshold = %f\n",
					minval, min_i, min_j, maxval, max_i, max_j, err_per);

	if (err_per > 3.0f)
	{
		printf("\n1st Image Test Failed\n");
		return 1;
	}

	cvShowImage("inputimg",src);
	*dst = (IplImage)(outputimg);
	cvShowImage("outputimg",dst);
	cvSaveImage("outputimg.jpg", dst);
	*dst = (IplImage)(ocv_outputimg);
	cvShowImage("ocv_outputimg",dst);
	cvSaveImage("ocv_outputimg.jpg", dst);
	*dst = (IplImage)(error_img0);
	cvShowImage("error_img",dst);
	cvSaveImage("error_img.jpg", dst);

	cvWaitKey(0);

	return 0;
}
