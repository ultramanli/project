// shiyan2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<highgui.hpp>
#include<imgproc.hpp>
#include<iostream>
using namespace cv;
using namespace std;
int main()
{

	


	namedWindow("Source", CV_WINDOW_AUTOSIZE );
	namedWindow("Blur", CV_WINDOW_AUTOSIZE);
	namedWindow("BoxFilter", CV_WINDOW_AUTOSIZE);
	namedWindow("MediaBlur", CV_WINDOW_AUTOSIZE);
	namedWindow("GaussianBlur", CV_WINDOW_AUTOSIZE);
	namedWindow("Sobel", CV_WINDOW_AUTOSIZE);
	namedWindow("Laplacian", CV_WINDOW_AUTOSIZE);
	
		Mat src = imread("test.jpg");
		Mat bluri,box,media,gaus,sobel,sobelx,sobely,lap;
		Mat gray(src.size(), CV_8UC1);
		cvtColor(src, gray, CV_BGR2GRAY);
		
		blur(src, bluri, Size(3, 3));//输入 输出 窗口尺寸

		boxFilter(src,box ,-1, Size(5, 5));//输入 输出 深度 窗口大小

		medianBlur(src, media, 5);//输入 输出 正方形窗口边长

		GaussianBlur(src, gaus, Size(3, 3), 0, 0);//输入 输出 窗口大小 自动计算x标准差 自动计算y标准差

		Sobel(src, sobelx, src.depth(), 1, 0);//输出 输出 深度 x方向
		Sobel(src, sobely, src.depth(), 0, 1);//输出 输出 深度 y方向
		convertScaleAbs(sobelx, sobelx);//求绝对值
		convertScaleAbs(sobely, sobely);
		addWeighted(sobelx, 0.5, sobely, 0.5, 0, sobel);//求和

		Laplacian(src, lap, CV_16S, 3, 1, 0, BORDER_DEFAULT);//输入 输出 深度 窗口大小 比例因子 存储模式
		convertScaleAbs(lap, lap);

		imshow("Source", src);
		imshow("Blur", bluri);
		imshow("BoxFilter", box);
		imshow("MediaBlur",media);
		imshow("GaussianBlur", gaus);
		imshow("Sobel", sobel);
		imshow("Laplacian", lap);
		cvWaitKey(0);
	return 0;
}

