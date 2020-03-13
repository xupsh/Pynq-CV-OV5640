#include <cassert>
#include <iostream>
#include <stdio.h>
#include "hls_opencv.h"
#include "hls_video.h"

#include "canny_edge.h"

int main(int argc, char** argv)
{
	cv::Mat in_img = cv::imread(argv[1]);

	cv::Mat hls_img(in_img.rows, in_img.cols, in_img.depth());
	cv::Mat ocv_img(in_img.rows, in_img.cols, in_img.depth());

	cv::Mat dilate_img(in_img.rows, in_img.cols, 3);
	cv::Mat erode_img(in_img.rows, in_img.cols, 3);

	cv::Mat diff(in_img.rows, in_img.cols, 1);

	cv::Canny(in_img, ocv_img, 80, 80);
	cv::Mat element = cv::getStructuringElement( 0,cv::Size(3, 3), cv::Point(-1, -1));

//	cv::dilate(in_img, dilate_img, element, cv::Point(-1, -1), 1, cv::BORDER_CONSTANT);
//	cv::erode(in_img, erode_img, element, cv::Point(-1, -1), 1, cv::BORDER_CONSTANT);

//	cv::Mat hls_img.create(in_img.rows, in_img.cols, in_img.depth());

	std::cout << in_img.rows << " " << in_img.cols << " " << in_img.channels() << std::endl;

	AXI_STREAM src_axi, dst_axi;

	cvMat2AXIvideo(in_img, src_axi);

	canny_edge(src_axi, dst_axi, 512, 512, 80, 80);

	AXIvideo2cvMat(dst_axi, hls_img);

	cv::imshow("ocv_img", ocv_img);
	cv::imshow("hls_img", hls_img);
	cv::absdiff(ocv_img,hls_img,diff);
	cv::imshow("diff", diff);
	cv::waitKey(0);

	return 0;

}
