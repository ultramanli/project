#include "stdafx.h"
#include<cv.h>
#include<highgui.h>

int g_slider_position = 0;
CvCapture* g_capture = NULL;
void onTrackbarSlide(int pos) {
	
	cvSetCaptureProperty(
		g_capture, CV_CAP_PROP_POS_FRAMES, pos
	);
	
}

int main(int argc,char** argv)
{
	cvNamedWindow("Example3", CV_WINDOW_AUTOSIZE);
	g_capture = cvCreateFileCapture(argv[1]);

	int frames = (int)cvGetCaptureProperty(g_capture, CV_CAP_PROP_FRAME_COUNT);
	if (frames != 0) {
		cvCreateTrackbar(
			"position", "Example3", &g_slider_position, frames, onTrackbarSlide
		);

		
	}
	
	IplImage* frame;
	while (1) {
		
	
		frame = cvQueryFrame(g_capture);
		if (!frame)break;
		cvShowImage("Example3", frame);
		char c = cvWaitKey(33);
		while (1) { 
			if (c != 32) { break; }
	     	if (c == 32) {
				char c2 = cvWaitKey(33);
				if (c2== 32) { break; }
				if(c2==27){
					cvReleaseCapture(&g_capture);
					cvDestroyWindow("Example3");
					return 0;
				}
			}
		}
		cvSetTrackbarPos("position", "Example3", cvGetCaptureProperty(g_capture, CV_CAP_PROP_POS_FRAMES));//跟随视频播放进度设置滚动条的位置 CV_CAP_PROP_POS_FRAMES视频当前帧数
		if (c == 27)break;

	}
	cvReleaseCapture(&g_capture);
	cvDestroyWindow("Example3");
    return 0;
}

