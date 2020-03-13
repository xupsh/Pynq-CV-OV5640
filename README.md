## PYNQ-CV-OV5640

In this PYNQ Overlay, picture is captured from an OV5640 camera which is connected to PL side, and several accelerated image processing algorithms are contained in this Overlay, you can choose which algorithm is enabled no need to download a new bitstream. In the example application notebook, you can configure the OV5640 camera and get the captured picture and display it on the notebook. The processed picature is displayed on the HDMI monitor which connected to the PL side.
![](./images/Architecture.png)

This PYNQ Overlay contains the below accelerated image processing algorithms.

* rgb2hsv	
* subsample
* equalizehist
* gaussianBlur
* sobel
* canny
* dilation
* erosion

## Quick Start

Open a terminal on your PYNQ board and run:

```
sudo pip3 install --upgrade git+https://github.com/xilinx/pynq-helloworld.git
```

or offline install:

```
sudo pip3 install --upgrade .
```

Currently this repository is compatible with [PYNQ image v2.4](http://www.pynq.io/board).


## Design Rebuilt

All IP and hls source codes are contains in this repository, you can recovery the hls and vivado project.

## License

**PYNQ** License : [BSD 3-Clause License](https://github.com/Xilinx/PYNQ/blob/master/LICENSE)
