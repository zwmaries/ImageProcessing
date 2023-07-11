#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

void drawing_demo(Mat& image)
{
	Rect rect;
	rect.x = 100;
	rect.y = 100;
	rect.width = 150;
	rect.height = 100;
	Mat bg = Mat::zeros(image.size(), image.type());
	rectangle(bg, rect, Scalar(0, 0, 255), -1, 8, 0);//绘制矩形
	circle(bg, Point(250, 200), 15, Scalar(255, 0, 0), -1, 8, 0);//绘制以15为半径的圆形
	line(bg, Point(100, 100), Point(250, 200), Scalar(0, 255, 0), 2, LINE_AA, 0);//绘制线条
	RotatedRect rrt;
	rrt.center = Point(150, 150);
	rrt.size = Size(50, 50);
	rrt.angle = 90.0;
	ellipse(bg, rrt, Scalar(0, 255, 255), 2, 8);

	Mat dst;
	addWeighted(image, 0.7, bg, 0.3, 0, dst);
	imshow("绘制演示", dst);
}

int main()
{
	Mat image = imread("D://BingDownload//football.jpg");
	drawing_demo(image);
	waitKey(0);
	return 0;
}