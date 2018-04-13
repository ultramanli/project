#include "ColorDetector.h"

#define RGB 1
//#define CIEL*a*b* 0
//设置颜色差距的阈值
void ColorDetector::setColorDistanceThreshold(int distance)
{
	if (distance < 0)
		distance = 0;
	maxDist = distance;
}
#ifdef RGB
//在RGB模式下设置需要检测的颜色
void ColorDetector::setTargetColor(cv::Vec3b color)
{
	target = color;
}
void ColorDetector::setTargetColor(uchar blue, uchar green, uchar red)
{
	target = cv::Vec3b(blue, green, red);
}
#else
//在CIEL*a*b*模式下设置需要检测的颜色
void ColorDetector::setTargetColor(uchar blue, uchar green, uchar red)
{
	//临时的单像素图像
	cv::Mat tmp(1, 1, CV_8UC3);
	tmp.at<cv::Vec3b>(0, 0) = cv::Vec3b(blue, green, red);
	//将目标颜色转换成Lab色彩空间
	cv::cvtColor(tmp, tmp, CV_BGR2Lab);
	target = tmp.at<cv::Vec3b>(0, 0);
}
#endif
//计算与目标颜色的差距
int  ColorDetector::getDistanceToTargetColor(const cv::Vec3b& color) const
{
	return getColorDistance(color, target);
}

//计算两个颜色之间的城区距离
int ColorDetector::getColorDistance(const cv::Vec3b& color1, const cv::Vec3b& color2) const
{
	return abs(color1[0]-color2[0]) + abs(color1[0]-color2[0]) + abs(color1[0]-color2[0]);
}


#ifdef RGB
//使用RGB的城区距离判断颜色
cv::Mat ColorDetector::process(const cv::Mat &image)
{
	result.create(image.size(), CV_8U);
	//取得迭代器
	cv::Mat_<cv::Vec3b>::const_iterator it = image.begin<cv::Vec3b>();
	cv::Mat_<cv::Vec3b>::const_iterator itend = image.end<cv::Vec3b>();
	cv::Mat_<uchar>::iterator itout = result.begin<uchar>();
	//对每个元素
	for ( ; it != itend; ++it, ++itout) {
		//比较与目标颜色的差距
		if (getDistanceToTargetColor(*it) <= maxDist) {
			*itout = 255;
		}
		else {
			*itout = 0;
		}
	}
	return result;
}
#else
//返回处理结果
cv::Mat ColorDetector::process(const cv::Mat &image)
{
	//必要时重新分配二值图像
	//与输入图像的尺寸相同，但使用单通道
	result.create(image.rows, image.cols, CV_8U);
	//转换成Lab色彩空间
	cv::cvtColor(image, converted, CV_BGR2Lab);
	//取得转换图像的迭代器
	cv::Mat_<cv::Vec3b>::iterator it = converted.begin<cv::Vec3b>();
	cv::Mat_<cv::Vec3b>::iterator itend = converted.end<cv::Vec3b>();
	//取得输出图像的迭代器
	cv::Mat_<uchar>::iterator itout = result.begin<uchar>();

	for ( ; it != itend; ++it, ++itout) {
		//比较与目标颜色的差距
		if (getDistanceToTargetColor(*it) <= maxDist) {
			*itout = 255;
		}
		else {
			*itout = 0;
		}
	}
	
	return result;
}
#endif
ColorDetector::~ColorDetector(void)
{
}


