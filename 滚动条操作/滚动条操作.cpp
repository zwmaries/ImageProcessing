#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

Mat src, dst, m;
int lightness = 50;
static void on_track(int,void*)
{
	m = Scalar(lightness, lightness, lightness);
	subtract(src, m, dst);
	imshow("���ȵ���", dst);
}

void tracking_bar_demo()
{
	Mat image= imread("D://BingDownload//lena.png");
	namedWindow("���ȵ���", WINDOW_AUTOSIZE);
	dst = Mat::zeros(image.size(), image.type());
	m= Mat::zeros(image.size(), image.type());
	src = image;
	int max_value = 100;
	createTrackbar("Value Bar:", "���ȵ���", &lightness, max_value, on_track);//����������
	on_track(50,0);
}

void key_demo()//���̲���
{
	Mat image = imread("D://BingDownload//lena.png");
	dst = Mat::zeros(image.size(), image.type());
	imshow("�������", image);
	while (true)
	{
		int c = waitKey(100);
		cout << c << endl;
		if (c == 27)//Esc �˳�
		{
			break;
		}
		if (c == 49)//1
		{
			cout << "you enter key #1" << endl;
			cvtColor(image, dst, COLOR_BGR2GRAY);
		}
		if (c == 50)//2
		{
			cout << "you enter key #2" << endl;
			cvtColor(image, dst, COLOR_BGR2HSV);
		}
		imshow("������Ӧ", dst);
	}
}

int main()
{
	key_demo();
	waitKey(0);
	return 0;
}