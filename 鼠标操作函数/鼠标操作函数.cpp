#include <iostream>
#include <opencv2/opencv.hpp>
#include "onMouse.h"
using namespace cv;
using namespace std;

int main()
{
	Mat image1 = imread("D://BingDownload//lena.png");
	if (image1.empty())
	{
		cout << "读取错误" << endl;
		return -1;
	}
	imshow("image1", image1);//显示图像
	setMouseCallback("image1", onMouse, reinterpret_cast<void*>(&image1));//关联图像显示窗口和onMouse函数
	waitKey(0);//暂停，保持图像显示，等待按键结束

	return 0;
}