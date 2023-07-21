#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void histogram_eq_demo(Mat& image)
{
	Mat gray;
	cvtColor(image, gray, COLOR_BGR2GRAY);
	imshow("灰度图", gray);
	Mat dst;
	equalizeHist(gray, dst);//直方图均衡化
	imshow("直方图均衡化", dst);
}

int main()
{
	Mat image, image_gray, hist;//定义输入图像，灰度图像，直方图
	image = imread("D://BingDownload//lena.png");
	//histogram_eq_demo(image);
	if (image.empty())
	{
		cout << "读取错误" << endl;
		return -1;
	}
	cvtColor(image, image_gray, COLOR_BGR2GRAY);//灰度化
	imshow("image_gray", image_gray);//显示灰度图像

	//获取图像直方图
	int histsize = 256;
	float ranges[] = { 0,256 };
	const float* histRanges = { ranges };
	calcHist(&image_gray, 1, 0, Mat(), hist, 1, &histsize, &histRanges, true, false);

	//创建直方图显示图像
	int hist_h = 300;//直方图的图像的高
	int hist_w = 512;//直方图的图像的宽
	int bin_w = hist_w / histsize;//直方图的等级
	Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(0, 0, 0));//绘制直方图显示的图像

	//绘制并显示直方图
	normalize(hist, hist, 0, hist_h, NORM_MINMAX, -1, Mat());//归一化直方图
	for (int i = 1; i < histsize; i++)
	{
		line(histImage, Point((i - 1) * bin_w, hist_h - cvRound(hist.at<float>(i - 1))), 
			Point((i)*bin_w, hist_h - cvRound(hist.at<float>(i))), Scalar(255, 0, 0), 2, 8, 0);
	}
	imshow("histImage", histImage);

	waitKey(0);
	return 0;
}