############################################################
## Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
############################################################
open_project dilation_project
set_top xf_dilation_accel
add_files ./xf_dilation_accel.cpp -cflags "-D__XFCV_HLS_MODE__ -Iinclude -Iinclude/src --std=c++0x"
add_files ./dilation_accel.cpp -cflags "-D__XFCV_HLS_MODE__ -Iinclude -Iinclude/src --std=c++0x"
add_files -tb ./lena.jpg
add_files -tb ./xf_dilation_tb.cpp -cflags "-D__XFCV_HLS_MODE__ -Iinclude -Iinclude/src --std=c++0x"
open_solution "solution1"
set_part {xc7z020clg400-1} -tool vivado
create_clock -period 10 -name default
#source "./dilation_color/solution1/directives.tcl"
csim_design -argv {lena.jpg} -clean -compiler gcc
#csynth_design
#cosim_design -argv {lena.jpg}
#export_design -format ip_catalog

