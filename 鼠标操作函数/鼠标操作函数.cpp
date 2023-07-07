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
		cout << "��ȡ����" << endl;
		return -1;
	}
	imshow("image1", image1);//��ʾͼ��
	setMouseCallback("image1", onMouse, reinterpret_cast<void*>(&image1));//����ͼ����ʾ���ں�onMouse����
	waitKey(0);//��ͣ������ͼ����ʾ���ȴ���������

	return 0;
}