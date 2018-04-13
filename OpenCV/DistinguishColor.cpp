// DistinguishColor.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <highgui.hpp>
#include <imgproc.hpp>

using namespace cv;
using namespace std;

//int main(int argc, char** argv)
//{
//	/*VideoCapture cap(0); //声明一个VideoCapture类cap，参数0为打开摄像头 若括号里为某视频文件的路径则为打开该视频      capture the video from web cam
//
//	if (!cap.isOpened())  //判断是否打开成功  if not success, exit program
//	{
//		cout << "Cannot open the web cam" << endl;
//		return -1;
//	}*/
//
//	namedWindow("Control", CV_WINDOW_NORMAL); //建立一个窗口，用来放H、S、V三个调节杆   create a window called "Control"
//	//namedWindow("Select", CV_WINDOW_NORMAL);
//	int iLowH = 100;//最小H（色调）阈值  默认100
//	int iHighH = 140;//最大H阈值 默认140   后面S、V类推
//
//	int iLowS = 90;//饱和度
//	int iHighS = 255;
//
//	int iLowV = 90;//亮度
//	int iHighV = 255;
//
//	int i = 0, j = 0;//循环变量
//	//Create trackbars in "Control" window
//	
//	cvCreateTrackbar("LowH", "Control", &iLowH, 179); //在Control中建立最小H值调节杆LowH，后面类推 色调取值范围Hue (0 - 179)
//	cvCreateTrackbar("HighH", "Control", &iHighH, 179);
//
//	cvCreateTrackbar("LowS", "Control", &iLowS, 255); //饱和度取值范围Saturation (0 - 255)
//	cvCreateTrackbar("HighS", "Control", &iHighS, 255);
//
//	cvCreateTrackbar("LowV", "Control", &iLowV, 255); //亮度取值范围Value (0 - 255)
//	cvCreateTrackbar("HighV", "Control", &iHighV, 255);
//	
//	while (true)
//	{   Mat imgOriginal= imread("C:\\Users\\LYH\\Pictures\\test.jpg");  //加上注释里的代码改为读一幅图
//	resize(imgOriginal, imgOriginal, Size(imgOriginal.cols /4, imgOriginal.rows / 4), 0, 0, INTER_LINEAR);
//
//		/*bool bSuccess = cap.read(imgOriginal); // 读摄像头cap到Mat类imgOrigial中 等价于cap >> imgOriginal;                     read a new frame from video
//		if (!bSuccess) //if not success, break loop
//		{
//			cout << "Cannot read a frame from video stream" << endl;
//			break;
//		}*/
//
//		Mat imgHSV;//定义用于HSV色彩空间的一个Mat
//		vector<Mat> hsvSplit;//定义H S V向量
//		cvtColor(imgOriginal, imgHSV, COLOR_BGR2HSV); //转换RGB到HSV   Convert the captured frame from BGR to HSV
//													  //因为我们读取的是彩色图，直方图均衡化需要在HSV空间做
//		split(imgHSV, hsvSplit);//分离HSV
//		equalizeHist(hsvSplit[2], hsvSplit[2]);//V直方图均衡化
//		merge(hsvSplit, imgHSV);//HSV融合
//		Mat imgThresholded;//识别结果Mat
//
//		inRange(imgHSV, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV), imgThresholded); //确定要识别的HSV阈值 二值化  Threshold the image
//		//减弱噪声（雪花点等）
//		Mat element = getStructuringElement(MORPH_RECT, Size(5, 5));
//		morphologyEx(imgThresholded, imgThresholded, MORPH_OPEN, element);//开操作(去除一些噪点) 开运算是对图像先腐蚀再膨胀，可以排除小团的物体       
//		morphologyEx(imgThresholded, imgThresholded, MORPH_CLOSE, element);//闭操作 (连接一些连通域) 闭运算是对图像先膨胀再腐蚀，可以排除小型黑洞
//
//		Mat result(imgOriginal.size(), imgOriginal.type());//带色彩显示的识别
//		for (i = 0; i < result.cols; i++)
//		{
//			
//			for (j = 0; j < result.rows; j++)
//			{
//				if (imgThresholded.at<uchar>(j, i) == 255)//二值图中为白色，显示为原颜色
//				{
//					result.at<cv::Vec3b>(j, i) = imgOriginal.at<cv::Vec3b>(j, i);
//				}
//				//else result.at<cv::Vec3b>(j, i) = (0, 0, 0);//二值图中为黑色，显示黑色
//			}
//		}
//
//		cvNamedWindow("result", CV_WINDOW_NORMAL);
//		cvNamedWindow("Thresholded Image", CV_WINDOW_NORMAL);
//		cvNamedWindow("Original", CV_WINDOW_NORMAL);
//		imshow("result", result);
//		imshow("Thresholded Image", imgThresholded); //二值识别结果 show the thresholded image
//		imshow("Original", imgOriginal); //原图 show the original image
//		char key = (char)waitKey(3);
//		if (key == 27)
//			break;
//	}
//
//	return 0;
//
//}

int main(int argc, char** argv)
{
	VideoCapture cap(0); //声明一个VideoCapture类cap，参数0为打开摄像头 若括号里为某视频文件的路径则为打开该视频      capture the video from web cam
	//cap.set(CAP_PROP_FRAME_WIDTH, 1920);
	//cap.set(CAP_PROP_FRAME_HEIGHT, 1080);
	if (!cap.isOpened())  //判断是否打开成功  if not success, exit program
	{
	cout << "Cannot open the web cam" << endl;
	return -1;
	}
	
	namedWindow("Select", CV_WINDOW_NORMAL); //建立一个窗口，用来放H、S、V三个调节杆   create a window called "Control"
	resizeWindow("Select", 640, 480);
											 //namedWindow("Select", CV_WINDOW_NORMAL);
	int black = 0,gray=0,white = 0,red=0,orange=0,yellow=0,green=0,qing=0,blue=0,purple=0;

	cvCreateTrackbar("黑", "Select", &black, 1); 
	cvCreateTrackbar("灰", "Select", &gray, 1);
	cvCreateTrackbar("白", "Select", &white, 1);
	cvCreateTrackbar("红", "Select", &red, 1);
	cvCreateTrackbar("橙", "Select", &orange, 1);
	cvCreateTrackbar("黄", "Select", &yellow, 1);
	cvCreateTrackbar("绿", "Select", &green, 1);
	cvCreateTrackbar("青", "Select", &qing, 1);
	cvCreateTrackbar("蓝", "Select", &blue, 1);
	cvCreateTrackbar("紫", "Select", &purple, 1);

	while (true)
	{
		int i = 0, j = 0;
		Mat imgOriginal;// = imread("C:\\Users\\LYH\\Pictures\\test.jpg");  //加上注释里的代码改为读一幅图
		//resize(imgOriginal, imgOriginal, Size(imgOriginal.cols / 4, imgOriginal.rows / 4), 0, 0, INTER_LINEAR);

		bool bSuccess = cap.read(imgOriginal); // 读摄像头cap到Mat类imgOrigial中 等价于cap >> imgOriginal;                     read a new frame from video
		if (!bSuccess) //if not success, break loop
		{
		cout << "Cannot read a frame from video stream" << endl;
		break;
		}

		Mat imgHSV;//定义用于HSV色彩空间的一个Mat
		vector<Mat> hsvSplit;//定义H S V向量
		cvtColor(imgOriginal, imgHSV, COLOR_BGR2HSV); //转换RGB到HSV   Convert the captured frame from BGR to HSV
													  //因为我们读取的是彩色图，直方图均衡化需要在HSV空间做
		split(imgHSV, hsvSplit);//分离HSV
		equalizeHist(hsvSplit[2], hsvSplit[2]);//V直方图均衡化
		merge(hsvSplit, imgHSV);//HSV融合
		
		Mat imgThresholded(imgOriginal.size(),CV_8U,Scalar(0));//识别结果Mat
		Mat mask;
		
		if (black == 1) {
			inRange(imgHSV, Scalar(0, 0, 0), Scalar(180, 255, 46), mask);
			imgThresholded = imgThresholded|mask;
		};
		if (gray == 1) {
			inRange(imgHSV, Scalar(0, 0, 46), Scalar(180, 43, 220), mask);
			imgThresholded = imgThresholded|mask;
		};
		if (white== 1) {
			inRange(imgHSV, Scalar(0, 0, 221), Scalar(180, 30, 255), mask);
			imgThresholded = imgThresholded|mask;
		};
		if (red == 1) {
			inRange(imgHSV, Scalar(0, 43, 46), Scalar(10, 255, 255), mask);
			imgThresholded = imgThresholded|mask;
			inRange(imgHSV, Scalar(156, 43, 46), Scalar(180, 255, 255), mask);
			imgThresholded = imgThresholded|mask;
		};
		if (orange== 1) {
			inRange(imgHSV, Scalar(11, 43, 46), Scalar(25, 255, 255), mask);
			imgThresholded = imgThresholded|mask;
		};
		if (yellow == 1) {
			inRange(imgHSV, Scalar(26, 43, 46), Scalar(34, 255, 255), mask);
			imgThresholded = imgThresholded|mask;
		};
		if (green== 1) {
			inRange(imgHSV, Scalar(35, 43, 46), Scalar(77, 255, 255), mask);
			imgThresholded = imgThresholded|mask;
		};
		if (qing == 1) {
			inRange(imgHSV, Scalar(78, 43, 46), Scalar(99, 255, 255), mask);
			imgThresholded = imgThresholded|mask;
		};
		if (blue== 1) {
			inRange(imgHSV, Scalar(100, 43, 46), Scalar(124, 255, 255), mask);
			imgThresholded = imgThresholded|mask;
		};
		if (purple == 1) {
			inRange(imgHSV, Scalar(125, 43, 46), Scalar(155, 255, 255), mask);
			imgThresholded = imgThresholded|mask;
		};
		
        //减弱噪声（雪花点等）
		Mat element = getStructuringElement(MORPH_RECT, Size(1, 1));
		morphologyEx(imgThresholded, imgThresholded, MORPH_OPEN, element);//开操作(去除一些噪点) 开运算是对图像先腐蚀再膨胀，可以排除小团的物体       
		morphologyEx(imgThresholded, imgThresholded, MORPH_CLOSE, element);//闭操作 (连接一些连通域) 闭运算是对图像先膨胀再腐蚀，可以排除小型黑洞
		
		Mat result(imgOriginal.size(), imgOriginal.type());//带色彩显示的识别
		for (i = 0; i < result.rows; i++)
		{
			uchar* data1 = imgOriginal.ptr<uchar>(i);
			uchar* data2 = result.ptr<uchar>(i);
			for (j = 0; j < result.cols; j++)
			{
				if (imgThresholded.at<uchar>(i, j) == 255)//二值图中为白色，显示为原颜色
				{
					data2[3*j] = data1[3*j];
					data2[3*j+1] = data1[3*j+1];
					data2[3*j+2] = data1[3*j+2];
					//result.at<cv::Vec3b>(i, j) = imgOriginal.at<cv::Vec3b>(i, j);
				}
				else if (imgThresholded.at<uchar>(i, j) == 0) {
					data2[3 * j] = 0;
					data2[3 * j+1] = 0;
					data2[3 * j+2] = 0;
					//result.at<cv::Vec3b>(i, j) = (0, 0, 0);//二值图中为黑色，显示黑色
				}
					
			}
		}
		
		cvNamedWindow("Result", CV_WINDOW_NORMAL);
		cvNamedWindow("Thresholded", CV_WINDOW_NORMAL);
		cvNamedWindow("Original", CV_WINDOW_NORMAL);
		cvResizeWindow("Result", 640, 480);
		cvResizeWindow("Thresholded", 640, 480);
		cvResizeWindow("Original", 640, 480);
		imshow("Result", result);
		imshow("Thresholded", imgThresholded); //二值识别结果 show the thresholded image
		imshow("Original", imgOriginal); //原图 show the original image
		char key = (char)waitKey(1);
		if (key == 27)
			break;
	}

	return 0;

	}