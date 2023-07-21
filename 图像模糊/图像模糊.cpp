#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

void blur_demo(Mat& image)//图像模糊
{
	Mat dst;
	blur(image, dst, Size(10, 10), Point(-1, -1));//此处Size(10, 10)表示卷积系数
	imshow("图像模糊", dst);
}

void bifilter_demo(Mat& image)//双边模糊
{
	Mat dst;
	bilateralFilter(image, dst, 0, 50, 10);
	imshow("双边模糊", dst);
}
int main()
{
	Mat image;
	image = imread("D://BingDownload//lena.png");
	imshow("原图", image);
	bifilter_demo(image);
	waitKey(0);
	return 0;
}