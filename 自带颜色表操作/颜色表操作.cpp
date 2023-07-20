#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

Mat image = imread("D://BingDownload//football.jpg");

void color_style_demo(Mat &image)
{
	int colormap[] = {
	COLORMAP_AUTUMN,
	COLORMAP_BONE,
	COLORMAP_JET,
	COLORMAP_WINTER,
	COLORMAP_RAINBOW,
	COLORMAP_OCEAN,
	COLORMAP_SUMMER,
	COLORMAP_SPRING,
	COLORMAP_COOL,
	COLORMAP_PINK,
	COLORMAP_HOT
	};
	Mat dst = Mat::zeros(image.size(), image.type());
	int index = 0;
	imshow("�������", image);
	while (true)
	{
		int c = waitKey(100);
		cout << c << endl;
		if (c == 27)//Esc �˳�
		{
			break;
		}
		applyColorMap(image, dst, colormap[index % 11]);
		index++;
		imshow("��ɫ�任", dst);
	}
}

void bitwise_demo()//���ص��߼�����
{
	imshow("����", image);
	Mat m1 = Mat::zeros(Size(256, 256), CV_8UC3);
	Mat m2 = Mat::zeros(Size(256, 256), CV_8UC3);
	rectangle(m1, Rect(100, 100, 80, 80), Scalar(255, 255, 0), -1, LINE_8, 0);
	rectangle(m2, Rect(150, 150, 80, 80), Scalar(0, 255, 255), -1, LINE_8, 0);
	imshow("m1", m1);
	imshow("m2", m2);
	Mat dst;
	bitwise_xor(m1, m2, dst);//������ֵ��λ���
	imshow("����λ����", dst);
}

void channels_demo()//ͨ���������ϲ���
{
	vector<Mat> mv;
	split(image, mv);//��ͼ������ֵ����mv��
	imshow("��ɫ", mv[0]);
	imshow("��ɫ", mv[1]);
	imshow("��ɫ", mv[2]);

	Mat dst;
	mv[0] = 0;
	//mv[1] = 0;
	merge(mv, dst);
	imshow("��ɫ", dst);

	int from_to[] = { 0,2,1,1,2,0 };
	mixChannels(&image, 1, &dst, 1, from_to, 3);
	imshow("ͨ�����", dst);
}

void inrange_demo()
{
	Mat hsv;
	cvtColor(image, hsv, COLOR_BGR2HSV);
	Mat mask;
	//h 0-180 s 0-255 v 0-255
	inRange(hsv, Scalar(100,43,46), Scalar(124,255,255), mask);
	imshow("����ͼ��", image);

	Mat redback = Mat::zeros(image.size(), image.type());
	redback = Scalar(40, 40, 200);
	bitwise_not(mask, mask);
	imshow("mask", mask);
	image.copyTo(redback, mask);
	imshow("roi������ȡ",redback);
}
int main()
{
	inrange_demo();
	waitKey(0);
	return 0;
}