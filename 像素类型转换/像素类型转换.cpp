#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

void norm_demo(Mat& image)
{
	Mat dst;
	cout << image.type() << endl;
	image.convertTo(image, CV_32F);
	cout << image.type() << endl;
	normalize(image, dst, 1.0, 0, NORM_MINMAX);
	cout << dst.type() << endl;
	imshow("图像数据归一化", dst);
}

int main()
{
	Mat image = imread("D://BingDownload//football.jpg");
	norm_demo(image);
	waitKey(0);
	return 0;
}