#include "hls_video.h"
#include "ap_axi_sdata.h"

#define MAX_WIDTH  1920
#define MAX_HEIGHT 1080
#define CHANNEL	   3

using namespace hls;

typedef hls::stream<ap_axiu<24,1,1,1> >  AXI_STREAM;
typedef hls::Scalar<3, unsigned char>  RGB_PIXEL;
typedef hls::Mat<MAX_HEIGHT, MAX_WIDTH, HLS_8UC3> RGB_IMAGE;

void rgb2hsv(AXI_STREAM& in, AXI_STREAM& out, int rows, int cols);

