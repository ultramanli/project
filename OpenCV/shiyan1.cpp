// shiyan1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<highgui.hpp>
#include<imgproc.hpp>
#include<iostream>
using namespace cv;
using namespace std;
int main()
{
	
	int bias = 0;
	int weight = 1;
	namedWindow("control", CV_WINDOW_NORMAL);
	cvCreateTrackbar("权重", "control", &weight,10);
	cvCreateTrackbar("偏移", "control", &bias, 255);

	namedWindow("source", CV_WINDOW_NORMAL);
	namedWindow("gray", CV_WINDOW_NORMAL);
	namedWindow("after", CV_WINDOW_NORMAL);

	while (1) {
		Mat src = imread("01.jpg");
		Mat gray(src.size(), CV_8UC1);
		cvtColor(src, gray, CV_BGR2GRAY);
		imshow("source", src);
		imshow("gray", gray);
		for (int i = 0; i < src.rows; i++) {
			uchar* data = gray.ptr<uchar>(i);
			for (int j = 0; j < src.cols; j++) {				
				if (weight*data[j] + bias >= 255) { data[j] = 255; }
				else { data[j] = weight*data[j] + bias; }
			}
		}
		imshow("after", gray);
		char c = waitKey(1);
		if (c == 27) { break; }
	}
    return 0;
}

