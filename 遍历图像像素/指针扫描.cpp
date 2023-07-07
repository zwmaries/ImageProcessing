#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

//指针扫描
int nodesm()
{
	Mat image1, output_image;//定义输入图像和输出图像
	image1 = imread("D://BingDownload//lena.png");
	if (image1.empty())
	{
		cout << "读取错误" << endl;
		return -1;
	}
	output_image = Mat(image1.size(), image1.type());//定义输出图像大小
	output_image = image1.clone();//克隆原图像素值

	int rows = image1.rows;//原图行数
	int stepx = image1.channels();//原图通道数
	int cols = (image1.cols) * image1.channels();//矩阵总列数

	for (int row = 1; row < (rows - 1); row++)   //对行遍历
	{
		const uchar* previous = image1.ptr<uchar>(row - 1);  //原图上一行指针
		const uchar* current = image1.ptr<uchar>(row);       //原图当前行指针
		const uchar* next = image1.ptr<uchar>(row + 1);      //原图下一行指针
		uchar* output = output_image.ptr<uchar>(row);        //输出图像当前行指针

		for (int col = stepx; col < (cols - stepx); col++)  //对列遍历
		{
			output[col] = saturate_cast<uchar>(5 * current[col] - (previous[col] + current[col - stepx] + current[col + stepx] + next[col]));
			//saturate_cast<uchar>(a)，当a在0—255时输出a，当a小于0输出0，当a大于255输出255，保证a的值在0~255之间
		}
	}

	imshow("image1", image1);
	imshow("output_image", output_image);
}

//自带卷积运算 filter2D
int filter2()
{
	Mat image1, output_image;
	image1 = imread("D://BingDownload//lena.png");
	if (image1.empty())
	{
		cout << "读取错误" << endl;
		return -1;
	}
	Mat kernel = (Mat_<char>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);//创建滤波器
	filter2D(image1, output_image, image1.depth(), kernel);

	imshow("image1", image1);
	imshow("output_image", output_image);

}
int main()
{
	
	filter2();
	waitKey(0);  //暂停，保持图像显示，等待按键结束
	return 0;
}