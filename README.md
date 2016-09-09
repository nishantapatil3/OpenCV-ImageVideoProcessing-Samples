# OpenCV examples

## Installing opencv:
```
$ sudo apt-get install build-essential
$ sudo apt-get install cmake git libgtk2.0-dev pkg-config libavcodec-dev libavformat-dev libswscale-dev
$ sudo apt-get install python-dev python-numpy libtbb2 libtbb-dev libjpeg-dev libpng-dev libtiff-dev libjasper-dev libdc1394-22-dev

$ git clone https://github.com/opencv/opencv.git

$ cd ~/opencv
$ cmake .
$ make
$ sudo make install
```

## NOTE:
### If encountered below error while running
OpenCV : libopencv_core.so.2.4: cannot open shared object file: No such file or directory:

just open file called /etc/ld.so.conf.d/opencv.conf then insert
```
/usr/local/opencv/
```
then type: ```sudo ldconfig```

## 1. Opencv Test
Test Opencv install and verify library linking

Written a small code in C++ to display an image.

## 2. Red Detection
Live color detection set to detect 'red'

## 3. Face and Eyes Detection
Live face and eye detection.

## 4. Background Subtraction
Delete static image with live image to obtaion background subtraction.
