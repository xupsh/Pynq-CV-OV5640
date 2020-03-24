overlay_name := cv_ov5640
design_name := cv_ov5640

block_design:
	vivado -mode batch -source $(overlay_name).tcl -notrace

clean:
	rm -rf $(overlay_name) *.jou *.log NA
