#include <iostream>  
#include<ctime>
#include<cmath>
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>  
#include"Tools.h"

using namespace cv;
Mat box,canvas,back;
void onMouse(int event, int x, int y, int type, void *param) {
	if (event == EVENT_LBUTTONDOWN) {
		Mat cache = back(Rect(
			Tools::clamp(back.cols - box.cols, 0, x),
			Tools::clamp(back.rows - box.rows, 0, y),
			box.cols, box.rows));
		addWeighted(cache, 0.5, box, 0.5, 0.0, cache);
	}
}
int main() {
	// ����һ��ͼƬ����Ϸԭ����    
	back = imread("pic.jpg");
	box = imread("box.jpg");
	Mat cache;
	int height = 0;
	float acceleration = 1, maxVelocity = 10;
	float velocity = maxVelocity;
	Mat canvas;
	// ����һ����Ϊ "��Ϸԭ��"����    
	namedWindow("��Ϸԭ��");
	// �ڴ�������ʾ��Ϸԭ��    
	imshow("��Ϸԭ��", back);
	// �ȴ�6000 ms�󴰿��Զ��ر�   
	int fps=70;
	time_t time = clock();
	time_t delta = (time_t)(1000.0/fps);
	//cvvWaitKey("Enter");
	void *fuck=nullptr;
	setMouseCallback("��Ϸԭ��", onMouse, fuck);
	for (;;) {
		waitKey(time+delta-clock());
		height += std::round(velocity);
		velocity -= acceleration;
		if (height <= 0) {
			height = 0;
			velocity = maxVelocity;
		}
		back.copyTo(canvas);
		cache = canvas(Rect(10,
			Tools::clamp(back.rows-box.rows,0,back.rows - height - box.rows),
			box.cols, box.rows));
		addWeighted(cache, 0.5, box, 0.5, 0.0, cache);
		imshow("��Ϸԭ��", canvas);
		time = clock();
	}
}