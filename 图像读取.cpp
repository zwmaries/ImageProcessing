#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
	Mat image; //创建一个空图像
	image = imread("D://BingDownload//tiankong.jpg");//读取文件夹中的图像
	//检测图像是否加载成功
	if (image.empty())
	{
		cout << "Could not open or find the image" << endl;
		return -1;
	}
	namedWindow("INAGE");//创建显示窗口
	imshow("IMAGE", image);//在窗口显示图像

	imwrite("tiankong.png", image);//保存图像为png格式，文件名称为tiankong
	waitKey(0);//暂停，保持图像显示，等待按键结束
	return 0;

}
