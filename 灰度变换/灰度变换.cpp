#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

//灰度反转
int GrayChange()
{
	Mat image1, output_image, image1_gray;//定义输入、输出、灰度图像
	image1 = imread("D://BingDownload//lena.png");
	if (image1.empty())
	{
		cout << "读取错误" << endl;
		return -1;
	}

	cvtColor(image1, image1_gray, COLOR_BGR2GRAY);//灰度化
	imshow(" image1_gray", image1_gray);
	output_image = image1_gray.clone();//复制灰度图像
	for (int i = 0; i < image1_gray.rows; i++)
	{
		for (int j = 0; j < image1_gray.cols; j++)
		{
			output_image.at<uchar>(i, j) = 255 - image1_gray.at<uchar>(i, j);//灰度反转

		}
	}
	imshow("output_image", output_image);//显示反转图像

}

//对数转换
int LogChange()
{
	Mat image1, output_image, image1_gray;   //定义输入图像，输出图像，灰度图像
	image1 = imread("D://BingDownload//lena.png");  //读取图像；
	if (image1.empty())
	{
		cout << "读取错误" << endl;
		return -1;
	}

	cvtColor(image1, image1_gray, COLOR_BGR2GRAY);  //灰度化
	imshow(" image1_gray", image1_gray);   //显示灰度图像

	output_image = image1_gray.clone();
	for (int i = 0; i < image1_gray.rows; i++)
	{
		for (int j = 0; j < image1_gray.cols; j++)
		{
			output_image.at<uchar>(i, j) = 6 * log((double)(image1_gray.at<uchar>(i, j)) + 1);  //对数变换 s=6*log(r+1)
		}
	}
	normalize(output_image, output_image, 0, 255, NORM_MINMAX);  //图像归一化，转到0~255范围内
	convertScaleAbs(output_image, output_image);  //数据类型转换到CV_8U
	imshow(" output_image", output_image);  //显示变换图像
}


int MiluChange()
{
	Mat image1, output_image, image1_gray;   //定义输入图像，输出图像，灰度图像
	image1 = imread("D://BingDownload//lena.png");  //读取图像；
	if (image1.empty())
	{
		cout << "读取错误" << endl;
		return -1;
	}

	cvtColor(image1, image1_gray, COLOR_BGR2GRAY);  //灰度化
	imshow(" image1_gray", image1_gray);   //显示灰度图像

	output_image = image1_gray.clone();
	for (int i = 0; i < image1_gray.rows; i++)
	{
		for (int j = 0; j < image1_gray.cols; j++)
		{
			output_image.at<uchar>(i, j) = 6 * pow((double)(image1_gray.at<uchar>(i, j)) , 0.8);  //幂律变换 s=6*r^0.5  幂指数小于1时增强暗区细节，幂指数大于1时增强亮区细节
		}
	}
	normalize(output_image, output_image, 0, 255, NORM_MINMAX);  //图像归一化，转到0~255范围内
	convertScaleAbs(output_image, output_image);  //数据类型转换到CV_8U
	imshow(" output_image", output_image);  //显示变换图像
}

int main()
{
	MiluChange();
	waitKey(0);
	return 0;
}