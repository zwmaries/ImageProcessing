#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
	Mat image; //����һ����ͼ��
	image = imread("D://BingDownload//tiankong.jpg");//��ȡ�ļ����е�ͼ��
	//���ͼ���Ƿ���سɹ�
	if (image.empty())
	{
		cout << "Could not open or find the image" << endl;
		return -1;
	}
	namedWindow("INAGE");//������ʾ����
	imshow("IMAGE", image);//�ڴ�����ʾͼ��

	imwrite("tiankong.png", image);//����ͼ��Ϊpng��ʽ���ļ�����Ϊtiankong
	waitKey(0);//��ͣ������ͼ����ʾ���ȴ���������
	return 0;

}
