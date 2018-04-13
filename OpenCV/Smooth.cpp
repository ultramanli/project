// Smooth.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cv.h>
#include<highgui.h>
using namespace std;
using namespace cv;

void example2_4(IplImage* image)
{
	
	cvShowImage("Example4-in", image);
	IplImage* out = cvCreateImage(cvSize(image->width/2,image->height/2), IPL_DEPTH_8U, 3);
	//cvSmooth(image, out, CV_GAUSSIAN, 3, 3);//Do Gaussian smooth
	cvPyrDown(image, out);//Do make 1/2
	cvShowImage("Example4-out", out);
	cvReleaseImage(&out);
	}
int main()
{
	CvCapture* capture = cvCreateFileCapture("e:\\samsung\\A\\sunshine.mp4");
	//CvCapture* capture = cvCreateCameraCapture(-1);
cvNamedWindow("Example4-in");
	cvNamedWindow("Example4-out");
	IplImage* img;
	while (1)
	{
		img = cvQueryFrame(capture);

		example2_4(img);
	
		char c=cvWaitKey(33);
		if (c == 27)break;
	}
	cvDestroyWindow("Example4-in");
	cvDestroyWindow("Example4-out");

    return 0;
}

