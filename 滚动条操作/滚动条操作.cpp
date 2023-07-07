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
	imshow("亮度调整", dst);
}

void tracking_bar_demo()
{
	Mat image= imread("D://BingDownload//lena.png");
	namedWindow("亮度调整", WINDOW_AUTOSIZE);
	dst = Mat::zeros(image.size(), image.type());
	m= Mat::zeros(image.size(), image.type());
	src = image;
	int max_value = 100;
	createTrackbar("Value Bar:", "亮度调整", &lightness, max_value, on_track);//创建滚动条
	on_track(50,0);
}

void key_demo()//键盘操作
{
	Mat image = imread("D://BingDownload//lena.png");
	dst = Mat::zeros(image.size(), image.type());
	imshow("输出窗口", image);
	while (true)
	{
		int c = waitKey(100);
		cout << c << endl;
		if (c == 27)//Esc 退出
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
		imshow("键盘响应", dst);
	}
}

int main()
{
	key_demo();
	waitKey(0);
	return 0;
}