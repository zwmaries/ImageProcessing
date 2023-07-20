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
	imshow("输出窗口", image);
	while (true)
	{
		int c = waitKey(100);
		cout << c << endl;
		if (c == 27)//Esc 退出
		{
			break;
		}
		applyColorMap(image, dst, colormap[index % 11]);
		index++;
		imshow("颜色变换", dst);
	}
}

void bitwise_demo()//像素的逻辑操作
{
	imshow("输入", image);
	Mat m1 = Mat::zeros(Size(256, 256), CV_8UC3);
	Mat m2 = Mat::zeros(Size(256, 256), CV_8UC3);
	rectangle(m1, Rect(100, 100, 80, 80), Scalar(255, 255, 0), -1, LINE_8, 0);
	rectangle(m2, Rect(150, 150, 80, 80), Scalar(0, 255, 255), -1, LINE_8, 0);
	imshow("m1", m1);
	imshow("m2", m2);
	Mat dst;
	bitwise_xor(m1, m2, dst);//将像素值按位异或
	imshow("像素位操作", dst);
}

void channels_demo()//通道分离与混合操作
{
	vector<Mat> mv;
	split(image, mv);//将图像像素值放入mv中
	imshow("蓝色", mv[0]);
	imshow("绿色", mv[1]);
	imshow("红色", mv[2]);

	Mat dst;
	mv[0] = 0;
	//mv[1] = 0;
	merge(mv, dst);
	imshow("红色", dst);

	int from_to[] = { 0,2,1,1,2,0 };
	mixChannels(&image, 1, &dst, 1, from_to, 3);
	imshow("通道混合", dst);
}

void inrange_demo()
{
	Mat hsv;
	cvtColor(image, hsv, COLOR_BGR2HSV);
	Mat mask;
	//h 0-180 s 0-255 v 0-255
	inRange(hsv, Scalar(100,43,46), Scalar(124,255,255), mask);
	imshow("输入图像", image);

	Mat redback = Mat::zeros(image.size(), image.type());
	redback = Scalar(40, 40, 200);
	bitwise_not(mask, mask);
	imshow("mask", mask);
	image.copyTo(redback, mask);
	imshow("roi区域提取",redback);
}
int main()
{
	inrange_demo();
	waitKey(0);
	return 0;
}