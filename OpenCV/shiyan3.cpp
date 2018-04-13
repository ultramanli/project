// shiyan3.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<highgui.hpp>
#include<imgproc.hpp>
using namespace cv;
using namespace std;
int main()
{
	Mat img = imread("test.jpg");//原图
	Mat gray(img.size(), CV_8UC1);//灰度图
	int ThresholdCannyMin = 220;//canny算法最小阈值
	int ThresholdCannyMax = 255;//canny算法最大阈值
	int ThresholdLine = 500;//
	vector<Vec2f> lines;//线集
	vector<Vec3f> circles;//圆集
	vector<vector<Point>> contours;//轮廓集
	vector<Vec4i> hierarchy;//hierarchy[i][0] ~hierarchy[i][3]=i个轮廓的后一个轮廓、前一个轮廓、父轮廓、内嵌轮廓的索引编号 默认值 - 1
	namedWindow("Control", CV_WINDOW_NORMAL);
	createTrackbar("Canny--Min", "Control", &ThresholdCannyMin, 255);
	createTrackbar("Canny--Max", "Control", &ThresholdCannyMax, 255);
	createTrackbar("Line", "Control", &ThresholdLine, 1000);
	cvtColor(img, gray, CV_BGR2GRAY);
	Mat canny(gray.size(), CV_8UC1);
	Mat houghline(gray.size(), CV_8UC3);
	Mat houghcircle(gray.size(), CV_8UC3);
	Mat contoursimg(gray.size(), CV_8UC3);
	while (1) {
		Canny(gray, canny, ThresholdCannyMin, ThresholdCannyMax, 3);
		
		houghline=canny.clone();
		houghcircle = canny.clone();
		contoursimg = canny.clone();
		HoughLines(houghline, lines, 1, CV_PI / 180, ThresholdLine, 0, 0);
		houghline = img.clone();
		
		
		HoughLines(houghline, lines, 1, CV_PI / 180, ThresholdLine, 0, 0);
		houghline = img.clone();
		for (int i = 0; i < lines.size(); i++) {
			float r = lines[i][0];//极径
			float t = lines[i][1];//极角
			Point pt1, pt2;//两个点
			double a = cos(t),b = sin(t);
			double x0 = a*r, y0 = b*r;
			pt1.x = cvRound(x0 + 1000 * (-b));
			pt1.y = cvRound(y0 + 1000 * (a));
			pt2.x = cvRound(x0 - 1000 * (-b));
			pt2.y = cvRound(y0 - 1000 * (a));
			line(houghline, pt1, pt2, Scalar(0, 0,255), 3, CV_AA);
		}
		
		HoughCircles(houghcircle, circles, CV_HOUGH_GRADIENT, 1.5, 10, 200, 50, 0, 0);
		houghcircle = img.clone();
		for (int i = 0; i < circles.size(); i++) {
			Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
			int radius = cvRound(circles[i][2]);
			
				circle(houghcircle, center, 3, Scalar(0, 255, 0), -1, 8, 0);
				circle(houghcircle, center, radius, Scalar(0, 0, 255), 3, 8, 0);
			
		}
		
		findContours(contoursimg, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point());//寻找轮廓函数
		
		Mat imageContours = Mat::zeros(canny.size(), CV_8UC1);//绘制提取的轮廓
		Mat Contours = Mat::zeros(canny.size(), CV_8UC1);  //保存轮廓点集
		for (int i = 0; i<contours.size(); i++)//contours.size()轮廓数
		{
			//contours[i]代表的是第i个轮廓，contours[i].size()代表的是第i个轮廓上所有的像素点数  
			for (int j = 0; j<contours[i].size(); j++)
			{
				//绘制出contours向量内所有的像素点  
				Point P = Point(contours[i][j].x, contours[i][j].y);
				Contours.at<uchar>(P) = 255;
			}
					

			//绘制轮廓  
			drawContours(imageContours, contours, i, Scalar(255), 1, 8, hierarchy);
		}
		imshow("Contours Image", imageContours); //轮廓  
		imshow("Point of Contours", Contours);   //向量contours内保存的所有轮廓点集
		
		
		
		
		Mat thresholdImg;
		threshold(gray, thresholdImg, 100, 255, CV_THRESH_BINARY);
		
		

		imshow("threshold", thresholdImg);
		imshow("Canny", canny);
		imshow("gray", gray);
		imshow("HoughLine", houghline);
		imshow("HoughCircle", houghcircle);
		char c=cvWaitKey(1);
		if (c == 27) { break; }
	}
    return 0;
}
