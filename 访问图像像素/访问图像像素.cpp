#include <iostream>
#include <opencv2/opencv.hpp>
#include "Salt.h"
using namespace std;
using namespace cv;

int main()
{
	Mat image1 = imread("D://BingDownload//lena.png");
	if (image1.empty())
	{
		cout << "��ȡ����" << endl;
		return -1;
	}
	imshow("image1", image1);//��ʾԭͼ��
	Salt(image1, 5000);//����5000��������
	imshow("image2", image1);//��ʾ����ͼ��
	waitKey(0);
	return 0;
}