#include <iostream>
#include <opencv2/opencv.hpp>
//使用Mat创建图像（矩阵）的常用形式有：
//1.创建一个空图像，大小为0: Mat image1;
//2.指定矩阵大小，指定数据类型：Mat image1(100,100,CV_8U);行数，列数，数据类型
//3.指定矩阵大小，指定数据类型，设置初始值：Mat image1(100,100,CV_8U,100);
using namespace std;
using namespace cv;

void test01()
{
	//创建空白图像
	Mat m3 = Mat::zeros(Size(400, 400), CV_8UC3);
	m3 = Scalar(255, 0, 0);
	cout << "width: " << m3.cols << " height:" << m3.rows << " channels:" << m3.channels() << endl;
	//cout << m3 << endl;
	//imshow("图像", m3);

	//Mat m4 = m3;//此时改变m4，m3也会改变
	Mat m4 = m3.clone();//此时相当于深拷贝，改变m4，m3不会改变
	m4 = Scalar(0, 255, 255);
	imshow("图像", m3);
	waitKey(0);//暂停，保持图像显示，等待按键结束
}

void test03()
{
	Mat image = imread("D://BingDownload//lena.png");
	imshow("原图像:", image);
	Mat dst;
	Mat m = Mat::zeros(image.size(), image.type());
	m = Scalar(50, 50, 50);
	//multiply(image, m, dst);//乘法
	//divide(image, m, dst);//除法
	//add(image, m, dst);//加法
	//subtract(image, m, dst);//减法
	//imshow("除法操作:", dst);

	//加法
	//int w = image.cols;
	//int h = image.rows;
	//int dims = image.channels();
	//for (int row = 0; row < h; row++)
	//{
	//	for (int col = 0; col < w; col++)
	//	{
	//		Vec3b p1 = image.at<Vec3b>(row, col);
	//		Vec3b p2 = m.at<Vec3b>(row, col);
	//		//saturate_cast<uchar>主要是为了防止颜色溢出操作
	//		dst.at<Vec3b>(row, col)[0] = saturate_cast<uchar>(p1[0] + p2[0]);
	//		dst.at<Vec3b>(row, col)[1] = saturate_cast<uchar>(p1[1] + p2[1]);
	//		dst.at<Vec3b>(row, col)[2] = saturate_cast<uchar>(p1[2] + p2[2]);
	//	}
	//}

	/*saturate_cast<uchar>原理大致如下
if(data<0) 
        data=0; 
elseif(data>255) 
    data=255;*/

	waitKey(0);
}

int test02()
{
	Mat image2= imread("D://BingDownload//lena.png");//读取图像
	if (image2.empty())
	{
		cout << "读取错误" << endl;
		return -1;
	}
	
	imshow("image2", image2);//显示图像
	Mat imageROI(image2, Rect(0, 0, 100, 100));//定义感兴趣的区域 0-100行 0-100列
	waitKey(0);//暂停，保持图像显示，等待按键结束

}
int main()
{
	test03();
	return 0;
}