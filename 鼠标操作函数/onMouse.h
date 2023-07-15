#pragma once
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

Point sp(-1, -1);//��ʼλ��
Point ep(-1, -1);//����λ��
Mat temp;
void onMouse(int event, int x, int y, int flags, void* param) //evnet:����¼����� x,y:������� flags������ĸ���
{
	Mat image = *((Mat*)param);
	if (event == EVENT_LBUTTONDOWN)
	{
		sp.x = x;
		sp.y = y;
		cout << "start point:" << sp << endl;
	}
	else if (event == EVENT_LBUTTONUP)
	{
		ep.x = x;
		ep.y = y;
		int dx = ep.x - sp.x;
		int dy = ep.y - sp.y;
		if (dx > 0 && dy > 0)
		{
			Rect box(sp.x, sp.y, dx, dy);
			rectangle(image, box, Scalar(0, 0, 255), 2, 8, 0);////��ȡ����Ȥ������
			imshow("������", image);
			imshow("ROI����", image(box));//�������Ȥ������
			//ready for next drawing
			sp.x = -1;
			sp.y = -1;
		}
	}
	else if (event == EVENT_MOUSEMOVE)
	{
		if (sp.x > 0 && sp.y > 0)
		{
			ep.x = x;
			ep.y = y;
			int dx = ep.x - sp.x;
			int dy = ep.y - sp.y;
			if (dx > 0 && dy > 0)
			{
				Rect box(sp.x, sp.y, dx, dy);
				temp.copyTo(image);//��temp������ͼ������ݸ��Ƶ�image������,��ˢ�»���
				rectangle(image, box, Scalar(0, 0, 255), 2, 8, 0);
				imshow("������", image);
			}
		}
	}
}

void mouse_drawing_demo(Mat& image)
{
	namedWindow("������", WINDOW_AUTOSIZE);
	setMouseCallback("������", onMouse,(void*)(&image));
	imshow("������", image);
	temp = image.clone();
}
//setMouseCallback("image1", onMouse, reinterpret_cast<void*>(&image1)); //����ͼ����ʾ���ں�onMouse����


//Matÿ�������ڵ����ݸ�ʽ---------- - Mat����
//Mat_<uchar>-------- - CV_8U��0-255��
//Mat<char>---------- - CV_8S��-128-127��
//Nat_<short>-------- - CV_16S��-32768-32767��
//Mat_<ushort>--------CV_16U��0-65535��
//Mat_<int>---------- - CV_32S��-2147483648-2147483647��
//Mat_<float>----------CV_32F��-FLT_MAX��FLT_MAX��INF��NAN��
//Mat_<double>--------CV_64F��-DBL_MAX��DBL_MAX��INF��NAN��

//Mat�������ͺ�ͨ����Ӧ��type()
//              C1          C2          C3          C4
//CV_8U         0           8           16          24
//CV_8S         1           9           17          25
//CV_16U        2          10           18          26
//CV_16S        3          11           19          27
//CV_32S        4          12           20          28
//CV_32F        5          13           21          29
//CV_64F        6          14           22          30