#include <iostream>
#include <opencv2/opencv.hpp>
#include "onMouse.h"
using namespace cv;
using namespace std;

int main()
{
	Mat image = imread("D://BingDownload//football.jpg");
	mouse_drawing_demo(image);
	waitKey(0);//��ͣ������ͼ����ʾ���ȴ���������
	return 0;
}