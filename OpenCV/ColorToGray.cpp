// ColorToGray.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cv.h>
#include<highgui.h>
#include<iostream>

using namespace cv;
using namespace std;
int main(int argc,char** argv)
{
	IplImage *imgc,*imgg;
	imgc = cvLoadImage(argv[1]);
	imgg = cvCreateImage(cvGetSize(imgc), IPL_DEPTH_8U, 1);
		cvCvtColor(imgc, imgg, CV_BGR2GRAY);
		const char* dir1;
		string dir2;
		cout << "Input out file dir:";
		cin >> dir2;
		cvSaveImage(dir2.c_str(), imgg);
		cvReleaseImage(&imgc);
		cvReleaseImage(&imgg);
		cout << "Complete!" << endl;
		
	
	return 0;
    
}

