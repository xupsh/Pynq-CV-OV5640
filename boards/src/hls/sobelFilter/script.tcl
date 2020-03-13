############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
############################################################

set prj_name [lindex $argv 0]
set top_file [format "%s.cpp" $prj_name]
set tb_file [format "%s_tb.cpp" $prj_name]

open_project $prj_name
set_top $prj_name
add_files $top_file
add_files -tb $tb_file
add_files -tb lena.jpg
open_solution "solution1"
set_part {xc7z020clg400-1} -tool vivado
create_clock -period 10 -name default
