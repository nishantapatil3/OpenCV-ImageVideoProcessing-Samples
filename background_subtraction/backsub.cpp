#include "stdafx.h"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/contrib/contrib.hpp"
#include "conio.h"

#include "time.h"
#include "opencv/cvaux.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/calib3d/calib3d.hpp"

using namespace std;
using namespace cv;
int main(int argc, char *argv[])
{
  int key = 0;

    CvSize imgSize;
    CvCapture* capture = cvCaptureFromFile( "S:\\offline object detection   database\\TwoEnterShop2cor.MPG" );

        IplImage* frame = cvQueryFrame( capture );
        imgSize = cvGetSize(frame);

        IplImage* grayImage = cvCreateImage( imgSize, IPL_DEPTH_8U, 1);
        IplImage* currframe = cvCreateImage(imgSize,IPL_DEPTH_8U,3);
        IplImage* destframe = cvCreateImage(imgSize,IPL_DEPTH_8U,3);

  if ( !capture )
  {
    fprintf( stderr, "Cannot open AVI!\n" );
    return 1;
  }

    int fps = ( int )cvGetCaptureProperty( capture, CV_CAP_PROP_FPS );

   cvNamedWindow( "dest", CV_WINDOW_AUTOSIZE );

   while( key != 'y' )
  {
  frame = cvQueryFrame( capture );

   currframe = cvCloneImage( frame );// copy frame to current
   frame = cvQueryFrame( capture );// grab frame
   cvAbsDiff(frame,currframe,destframe);

   cvCvtColor(destframe,grayImage,CV_RGB2GRAY);
   cvSmooth(grayImage,grayImage,CV_MEDIAN,3,3,0);
   cvAdaptiveThreshold(grayImage,grayImage,230,CV_THRESH_BINARY,CV_ADAPTIVE_THRESH_GAUSSIAN_C,3,5);

     cvDilate(grayImage, grayImage, 0,1);
     cvErode(grayImage,grayImage, 0, 0);
  if(key==27 )break;
  cvShowImage( "fram",currframe);
  cvShowImage( "dest",grayImage);
   key = cvWaitKey( 100 );
   }
  cvDestroyWindow( "dest" );
  cvReleaseCapture( &capture );
  return 0;
}
