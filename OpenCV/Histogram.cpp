// Histogram.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <highgui.hpp>
#include <imgproc.hpp>
#include <iostream>
using namespace std;
using namespace cv;
class Histogram1D {
private:
	int histSize[1];//直方图中箱子bin的数量 eg:灰度图有256个bin
	float hranges[2];//值范围
	const float* ranges[1];//值范围的指针
	int channels[1];//要检查的通道数量
public:
	Histogram1D()
	{
		histSize[0]=256;//256个箱子bin
		hranges[0] = 0.0;//值从0开始（包含）
		hranges[1] = 256.0;//到255结束
		ranges[0] = hranges;//指针指向值范围数组头
		channels[0]=0;//关心0通道
	}
    
	Mat getHistogram(const Mat &image)
	{
	Mat hist;
	cv::calcHist(&image, 
		1,//一个图像的直方图
		channels,//使用的通道
		Mat(),//不适用掩码
		hist,//结果直方图
		1,//一维
		histSize,//箱子数量 
		ranges//像素值的范围
	);
	return hist;
	}

	Mat getHistogramImage(const Mat &image, int zoom = 1) {
		Mat hist = getHistogram(image);
		return getImageOfHistogram(hist, zoom);
	}

	static Mat getImageOfHistogram(const Mat &hist, int zoom) {
		double maxval = 0;
		double minval = 0;
		minMaxLoc(hist, &minval, &maxval, 0, 0);
		int histSize = hist.rows;
		Mat histImg(histSize*zoom, histSize*zoom, CV_8U, Scalar(255));
		int hpt = static_cast<int>(0.9*histSize);
		for (int h = 0; h < histSize; h++) {
			float binval = hist.at<float>(h);
			if (binval > 0) {
				int intensity = static_cast<int>(binval*hpt / maxval);
				line(histImg,
					Point(h*zoom, histSize*zoom),
					Point(h*zoom,(histSize-intensity)*zoom),
					Scalar(0),
					zoom);
					
			}
		}
		return histImg;
	}
};



int main()
{
	Mat image = imread("ll.jpg");
	Histogram1D h;
	Mat histo = h.getHistogram(image);
	int num = 0;
	for (int i = 0; i < 256; i++)
	{
		num = num + histo.at<float>(i);
		cout << "像素灰度值为 " << i << " 的像素=" << histo.at<float>(i) << endl;
	}
	cout <<endl<< "像素总数=" << num<<endl;
	cout << "分辨率=" << image.cols << "*" << image.rows << "=" << image.cols*image.rows<<endl;
	
	Mat dst(Size(h.getHistogramImage(image).cols*4, h.getHistogramImage(image).rows*4), h.getHistogramImage(image).type());
	resize(h.getHistogramImage(image),
		dst,
		dst.size()
	);
	imshow("123", dst);
	char c = cvWaitKey(0);
	return 0;
}

