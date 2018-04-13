// Play_Video.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<highgui.h>
using namespace std;
using namespace cv;


int main(int argc , char** argv)
{
	CvCapture* capture;
	if (argc == 1) {
capture = cvCreateCameraCapture(0);
	}
	else { capture = cvCreateFileCapture(argv[1]);

	}
	assert(capture != NULL);
	cvNamedWindow("Example2", CV_WINDOW_AUTOSIZE);
	
	
	IplImage* frame;
	while (1)
	{
		frame = cvQueryFrame(capture);
		if (!frame)break;
		cvShowImage("Example2", frame);
		char c = cvWaitKey(33);
		if (c == 27)break;
	}
	cvReleaseCapture(&capture);
	cvDestroyWindow("Example2");
    return 0;
}
