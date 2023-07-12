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
//多边形填充与绘制
void polyline_drawing_demo()
{
	Mat canvas = Mat::zeros(Size(512, 512), CV_8UC3);
	Point p1(100, 100);
	Point p2(350, 100);
	Point p3(450, 280);
	Point p4(320, 450);
	Point p5(80, 400);
	vector<Point> pts;
	pts.push_back(p1);
	pts.push_back(p2);
	pts.push_back(p3);
	pts.push_back(p4);
	pts.push_back(p5);
	//polylines(canvas, pts, true, Scalar(0, 0, 255), 1, 8, 0);//绘制多边形（不可填充）
	//fillPoly(canvas, pts, Scalar(255, 0, 255),8,0);//填充多边形
	vector<vector<Point>> contours;
	contours.push_back(pts);
	drawContours(canvas, contours, -1, Scalar(255, 0, 0), -1);
	imshow("多边形绘制", canvas);
}

int main()
{
	Mat image = imread("D://BingDownload//football.jpg");
	polyline_drawing_demo();
	waitKey(0);
	return 0;
}