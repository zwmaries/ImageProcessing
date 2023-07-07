#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
	Mat img1 = imread("", 0);//��ȡ�Ҷ�ͼ��
	if (img1.empty())
	{
		cout << "��ȡ����" << endl;
		return -1;
	}
	imshow("image1", img1);
	Mat img2 = Mat(img1.size(), CV_8U, Scalar(0));

	//opencv�Դ�canny��⺯��
	Canny(img1, img2, 50, 150);
	imshow("img2", img2);
	waitKey();
	return 0;
}
