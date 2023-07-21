#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

void blur_demo(Mat& image)//ͼ��ģ��
{
	Mat dst;
	blur(image, dst, Size(10, 10), Point(-1, -1));//�˴�Size(10, 10)��ʾ���ϵ��
	imshow("ͼ��ģ��", dst);
}

void bifilter_demo(Mat& image)//˫��ģ��
{
	Mat dst;
	bilateralFilter(image, dst, 0, 50, 10);
	imshow("˫��ģ��", dst);
}
int main()
{
	Mat image;
	image = imread("D://BingDownload//lena.png");
	imshow("ԭͼ", image);
	bifilter_demo(image);
	waitKey(0);
	return 0;
}