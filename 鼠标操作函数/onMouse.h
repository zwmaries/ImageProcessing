#pragma once
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void onMouse(int event, int x, int y, int flags, void* param) //evnet:����¼����� x,y:������� flags������ĸ���
{
	Mat* im = reinterpret_cast<Mat*>(param);
	switch (event)
	{
	case EVENT_LBUTTONDOWN:
		//��ʾͼ������ֵ
		if (static_cast<int>(im->channels())==1)
		{
			//��ͼ��Ϊ��ͨ��ͼ������ʾ������������Լ��Ҷ�ֵ
			switch (im->type())
			{
			case 0:
				cout << "at (" << x << ", " << y << " ) value is: " << static_cast<int>(im->at<uchar>(Point(x, y))) << endl; 
				break;
			case 1:
				cout << "at (" << x << ", " << y << " ) value is: " << static_cast<int>(im->at<char>(Point(x, y))) << endl; 
				break;
			case 2:
				cout << "at (" << x << ", " << y << " ) value is: " << static_cast<int>(im->at<ushort>(Point(x, y))) << endl; 
				break;
			case 3:
				cout << "at (" << x << ", " << y << " ) value is: " << static_cast<int>(im->at<short>(Point(x, y))) << endl; 
				break;
			case 4:
				cout << "at (" << x << ", " << y << " ) value is: " << static_cast<int>(im->at<int>(Point(x, y))) << endl; 
				break;
			case 5:
				cout << "at (" << x << ", " << y << " ) value is: " << static_cast<int>(im->at<float>(Point(x, y))) << endl; 
				break;
			case 6:
				cout << "at (" << x << ", " << y << " ) value is: " << static_cast<int>(im->at<double>(Point(x, y))) << endl; 
				break;

			}
		}
		else
		{
			//��ͼ��Ϊ��ɫͼ������ʾ����������Լ���Ӧ��B, G, Rֵ
			cout << "at (" << x << ", " << y << ")"
				<< "  B value is: " << static_cast<int>(im->at<Vec3b>(Point(x, y))[0])
				<< "  G value is: " << static_cast<int>(im->at<Vec3b>(Point(x, y))[1])
				<< "  R value is: " << static_cast<int>(im->at<Vec3b>(Point(x, y))[2])
				<< endl;
		}

		break;
	}
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