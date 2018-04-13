// CannyCamera.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<highgui.h>
#include<highgui.hpp>
#include<cv.h>
using namespace cv;
int main(int argc,char** argv)
{
	VideoCapture input(0);
	Mat img;
	IplImage* framec,*frameg;
	input >> img;
	framec = &IplImage(img);
	cvNamedWindow("PC1", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("PC2", CV_WINDOW_AUTOSIZE);
	while (1)
	{
		input >> img;
		framec = &IplImage(img);
		frameg = cvCreateImage(cvGetSize(framec), IPL_DEPTH_8U, 1);
		cvCvtColor(framec, frameg, CV_BGR2GRAY);
		cvCanny(frameg, frameg, 50, 50, 3);
		cvShowImage("PC1", frameg);
		cvShowImage("PC2", framec);
		framec = NULL;
		frameg = NULL;
		char c = cvWaitKey(33);
		if (c == 27) { break; }
	}
	cvReleaseImage(&frameg);
	cvReleaseImage(&framec);
	img.release();
	cvDestroyWindow("PC1");
	cvDestroyWindow("PC2");
	return 0;
}

