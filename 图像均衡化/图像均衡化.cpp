#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	Mat image, image_gray, image_enhanced;//��������ͼ�񣬻Ҷ�ͼ��ֱ��ͼ
	image = imread("D:/BingDownload/lena.png");//��ȡͼ��
	if (image.empty())
	{
		cout << "��ȡ����" << endl;
		return -1;
	}
	cvtColor(image, image_gray, COLOR_BGR2GRAY);//�ҶȻ�
	imshow("image_gray", image_gray);//��ʾ�Ҷ�ͼ��

	equalizeHist(image_gray, image_enhanced);//ֱ��ͼ���⻯
	imshow("image_enhanced", image_enhanced);//��ʾ��ǿͼ��

	waitKey(0);
	return 0;
}