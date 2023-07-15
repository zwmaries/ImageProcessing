#include <iostream>
#include <opencv2/opencv.hpp>
#include "onMouse.h"
using namespace cv;
using namespace std;

int main()
{
	Mat image = imread("D://BingDownload//football.jpg");
	mouse_drawing_demo(image);
	waitKey(0);//暂停，保持图像显示，等待按键结束
	return 0;
}