// Canny.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cv.h>
#include<highgui.h>
using namespace std;
using namespace cv;

int main(int argc,char** argv)
{   cvNamedWindow("in", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("out", CV_WINDOW_AUTOSIZE);
	CvCapture* capture = cvCreateFileCapture(argv[1]);
	IplImage* img;
	//IplImage* img = cvLoadImage(argv[1]);
	IplImage* imgg;// = cvCreateImage(cvGetSize(img), IPL_DEPTH_8U, 1);
	IplImage* out;// = cvCreateImage(cvGetSize(img), IPL_DEPTH_8U, 1);
	while (1) {
		img = cvQueryFrame(capture);
		imgg= cvCreateImage(cvGetSize(img), IPL_DEPTH_8U, 1);
		out= cvCreateImage(cvGetSize(img), IPL_DEPTH_8U, 1);
		cvCvtColor(img, imgg, CV_BGR2GRAY);
	    cvCanny(imgg, out, 10, 100, 3);
cvShowImage("in", img);
	cvShowImage("out", out);
	if (!img)break;
	char c = cvWaitKey(33);
	if (c == 27)break;



	}
	
	
	
//	cvWaitKey(0);
	cvReleaseCapture(&capture);
	cvReleaseImage(&img);
	cvReleaseImage(&imgg);
	cvReleaseImage(&out);
	
	cvDestroyWindow("in");
	cvDestroyWindow("out");
    return 0;
}
