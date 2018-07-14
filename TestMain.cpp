#include <iostream>  
#include<ctime>
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>  

using namespace cv;

int main() {
	// 读入一张图片（游戏原画）    
	Mat back = imread("pic.jpg");
	Mat box = imread("box.jpg");
	Mat cache;
	int height = 0, acceleration = 1, velocity = 10;
	Mat canvas;
	// 创建一个名为 "游戏原画"窗口    
	namedWindow("游戏原画");
	// 在窗口中显示游戏原画    
	imshow("游戏原画", back);
	// 等待6000 ms后窗口自动关闭   
	time_t time = clock();
	time_t delta = 20;
	//cvvWaitKey("Enter");
	for (;;) {
		waitKey(int(delta));
		height += velocity;
		velocity -= acceleration;
		back.copyTo(canvas);
		cache = canvas(Rect(10, back.rows - height - box.rows, box.cols, box.rows));
		addWeighted(cache, 0.5, box, 0.5, 0.0, cache);
		imshow("游戏原画", canvas);
		if (height <= 0) {
			height = 0;
			velocity = 10;
		}
		time = clock();
	}
}