#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

void norm_demo(Mat& image)//��һ��
{
	Mat dst;
	cout << image.type() << endl;
	image.convertTo(image, CV_32F);//ת����������ΪCV_32F
	cout << image.type() << endl;
	normalize(image, dst, 1.0, 0, NORM_MINMAX);
	cout << dst.type() << endl;
	imshow("ͼ�����ݹ�һ��", dst);
}

void resize_demo(Mat& image)//ͼ����� 
{
	Mat zoomin, zoomout;
	int h = image.rows;
	int w = image.cols;
	resize(image, zoomin, Size(h / 1.5, w / 1.5), 0, 0, INTER_LINEAR);
	imshow("zoomin", zoomin);
	resize(image, zoomout, Size(h *1.5, w*1.5), 0, 0, INTER_LINEAR);
	imshow("zoomout", zoomout);

}

void filp_demo(Mat& image)//ͼ��ת
{
	Mat dst;
	//flip(image, dst, 0);//0 ���·�ת
	//flip(image, dst, 1);//1 ���ҷ�ת
	flip(image, dst, -1);//-1 ��ת180��
	imshow("ͼ��ת", dst);
}

void rotate_demo(Mat& image)//ͼ����ת
{
	Mat dst, m;
	int h = image.rows;
	int w = image.cols;
	m = getRotationMatrix2D(Point2f(w / 2, h / 2), 45, 1.0);
	
	//m=[cos sin 0
    //  -sin cos 0]
	double cos = abs(m.at<double>(0, 0));
	double sin = abs(m.at<double>(0, 1));
	int nw = cos * w + sin * h;//ͼ����ת��ĳ���
	int nh = sin * w + cos * h;
	m.at<double>(0, 2) += (nw / 2 - w / 2);//ƽ��ͼ�����ĵ�
	m.at<double>(1, 2) += (nh / 2 - h / 2);

	warpAffine(image, dst, m, Size(nw,nh), INTER_LINEAR,0,Scalar(0,255,255));
	imshow("��ת��", dst);
}
int main()
{
	Mat image = imread("D://BingDownload//football.jpg");
	imshow("ԭͼ", image);
	rotate_demo(image);
	waitKey(0);
	return 0;
}