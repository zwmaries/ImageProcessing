#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	Mat image, image_gray, image_enhanced;//定义输入图像，灰度图像，直方图
	image = imread("D:/BingDownload/lena.png");//读取图像
	if (image.empty())
	{
		cout << "读取错误" << endl;
		return -1;
	}
	cvtColor(image, image_gray, COLOR_BGR2GRAY);//灰度化
	imshow("image_gray", image_gray);//显示灰度图像

	equalizeHist(image_gray, image_enhanced);//直方图均衡化
	imshow("image_enhanced", image_enhanced);//显示增强图像

	waitKey(0);
	return 0;
}