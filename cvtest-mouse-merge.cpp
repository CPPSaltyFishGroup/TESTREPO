#include <iostream>  
#include <opencv.hpp>
#include <string>
#include <vector>

using namespace std;
using namespace cv;


int main()
{
	void onMouse(int event, int x, int y, int type, void *param);
	int cvAdd4cMat_q(cv::Mat &dst, cv::Mat &scr, double scale);
	Mat temp;
	Mat start = imread("Start.jpg");
	Mat plane = imread("灰色飞机1.png", -1);//参数-1为读取四个通道
	Mat imageROI = start(cv::Rect(50, 50, plane.cols, plane.rows));//取底图需要合并的区域
	cvAdd4cMat_q(imageROI, plane, 1);

	namedWindow("game", WINDOW_NORMAL);
	cvResizeWindow("game", 800, 500);
	setMouseCallback("game", onMouse, (void*)&temp);//设置鼠标回调函数
	start.copyTo(temp);
	while (1)
	{
		imshow("game", temp);
		if (waitKey(10) == 27) break;
	}
	waitKey(0);
	return 0;
}

void onMouse(int event, int x, int y, int type, void *param)
{             // 事件   鼠标坐标  附加事件  接受参数
	Mat playing = imread("plane.jpg");
	switch (event)
	{
	case(EVENT_LBUTTONDOWN):
	{
		playing.copyTo(*(Mat*)param);
		break;
	}
	case(EVENT_MOUSEMOVE):
	{

		break;
	}
	}
}

int cvAdd4cMat_q(cv::Mat &dst, cv::Mat &scr, double scale)
{
	if (dst.channels() != 3 || scr.channels() != 4)
	{
		return true;
	}
	if (scale < 0.01)
		return false;
	std::vector<cv::Mat>scr_channels;
	std::vector<cv::Mat>dstt_channels;
	split(scr, scr_channels);
	split(dst, dstt_channels);
	CV_Assert(scr_channels.size() == 4 && dstt_channels.size() == 3);
	cout << scr_channels[3] << endl;
	if (scale < 1)
	{
		scr_channels[3] *= scale;
		scale = 1;
	}
	for (int i = 0; i < 3; i++)
	{
		dstt_channels[i] = dstt_channels[i].mul(255.0 / scale - scr_channels[3], scale / 255.0);
		dstt_channels[i] += scr_channels[i].mul(scr_channels[3], scale / 255.0);
	}
	merge(dstt_channels, dst);
	return true;
}