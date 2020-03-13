
`timescale 1 ns / 1 ps

  module gaussian_mul_mul_Aem_DSP48_9(a, b, p);
input [8 - 1 : 0] a;
input [12 - 1 : 0] b;
output [20 - 1 : 0] p;

assign p = $unsigned (a) * $unsigned (b);

endmodule

`timescale 1 ns / 1 ps
module gaussian_mul_mul_Aem(
    din0,
    din1,
    dout);

parameter ID = 32'd1;
parameter NUM_STAGE = 32'd1;
parameter din0_WIDTH = 32'd1;
parameter din1_WIDTH = 32'd1;
parameter dout_WIDTH = 32'd1;
input[din0_WIDTH - 1:0] din0;
input[din1_WIDTH - 1:0] din1;
output[dout_WIDTH - 1:0] dout;



gaussian_mul_mul_Aem_DSP48_9 gaussian_mul_mul_Aem_DSP48_9_U(
    .a( din0 ),
    .b( din1 ),
    .p( dout ));

endmodule

