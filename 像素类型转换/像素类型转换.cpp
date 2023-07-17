#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

void norm_demo(Mat& image)//归一化
{
	Mat dst;
	cout << image.type() << endl;
	image.convertTo(image, CV_32F);//转换数据类型为CV_32F
	cout << image.type() << endl;
	normalize(image, dst, 1.0, 0, NORM_MINMAX);
	cout << dst.type() << endl;
	imshow("图像数据归一化", dst);
}

void resize_demo(Mat& image)//图像放缩 
{
	Mat zoomin, zoomout;
	int h = image.rows;
	int w = image.cols;
	resize(image, zoomin, Size(h / 1.5, w / 1.5), 0, 0, INTER_LINEAR);
	imshow("zoomin", zoomin);
	resize(image, zoomout, Size(h *1.5, w*1.5), 0, 0, INTER_LINEAR);
	imshow("zoomout", zoomout);

}

void filp_demo(Mat& image)//图像翻转
{
	Mat dst;
	//flip(image, dst, 0);//0 上下翻转
	//flip(image, dst, 1);//1 左右翻转
	flip(image, dst, -1);//-1 旋转180度
	imshow("图像翻转", dst);
}

void rotate_demo(Mat& image)//图像旋转
{
	Mat dst, m;
	int h = image.rows;
	int w = image.cols;
	m = getRotationMatrix2D(Point2f(w / 2, h / 2), 45, 1.0);
	
	//m=[cos sin 0
    //  -sin cos 0]
	double cos = abs(m.at<double>(0, 0));
	double sin = abs(m.at<double>(0, 1));
	int nw = cos * w + sin * h;//图像旋转后的长度
	int nh = sin * w + cos * h;
	m.at<double>(0, 2) += (nw / 2 - w / 2);//平移图形中心点
	m.at<double>(1, 2) += (nh / 2 - h / 2);

	warpAffine(image, dst, m, Size(nw,nh), INTER_LINEAR,0,Scalar(0,255,255));
	imshow("旋转后", dst);
}
int main()
{
	Mat image = imread("D://BingDownload//football.jpg");
	imshow("原图", image);
	rotate_demo(image);
	waitKey(0);
	return 0;
}