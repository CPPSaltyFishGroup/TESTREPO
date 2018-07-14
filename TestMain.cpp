#include <iostream>  
#include<ctime>
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>  

using namespace cv;

int main() {
	// ����һ��ͼƬ����Ϸԭ����    
	Mat back = imread("pic.jpg");
	Mat box = imread("box.jpg");
	Mat cache;
	int height = 0, acceleration = 1, velocity = 10;
	Mat canvas;
	// ����һ����Ϊ "��Ϸԭ��"����    
	namedWindow("��Ϸԭ��");
	// �ڴ�������ʾ��Ϸԭ��    
	imshow("��Ϸԭ��", back);
	// �ȴ�6000 ms�󴰿��Զ��ر�   
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
		imshow("��Ϸԭ��", canvas);
		if (height <= 0) {
			height = 0;
			velocity = 10;
		}
		time = clock();
	}
}