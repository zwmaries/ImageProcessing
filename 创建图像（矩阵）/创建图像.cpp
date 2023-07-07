#include <iostream>
#include <opencv2/opencv.hpp>
//ʹ��Mat����ͼ�񣨾��󣩵ĳ�����ʽ�У�
//1.����һ����ͼ�񣬴�СΪ0: Mat image1;
//2.ָ�������С��ָ���������ͣ�Mat image1(100,100,CV_8U);��������������������
//3.ָ�������С��ָ���������ͣ����ó�ʼֵ��Mat image1(100,100,CV_8U,100);
using namespace std;
using namespace cv;

void test01()
{
	//�����հ�ͼ��
	Mat m3 = Mat::zeros(Size(400, 400), CV_8UC3);
	m3 = Scalar(255, 0, 0);
	cout << "width: " << m3.cols << " height:" << m3.rows << " channels:" << m3.channels() << endl;
	//cout << m3 << endl;
	//imshow("ͼ��", m3);

	//Mat m4 = m3;//��ʱ�ı�m4��m3Ҳ��ı�
	Mat m4 = m3.clone();//��ʱ�൱��������ı�m4��m3����ı�
	m4 = Scalar(0, 255, 255);
	imshow("ͼ��", m3);
	waitKey(0);//��ͣ������ͼ����ʾ���ȴ���������
}

void test03()
{
	Mat image = imread("D://BingDownload//lena.png");
	imshow("ԭͼ��:", image);
	Mat dst;
	Mat m = Mat::zeros(image.size(), image.type());
	m = Scalar(50, 50, 50);
	//multiply(image, m, dst);//�˷�
	//divide(image, m, dst);//����
	//add(image, m, dst);//�ӷ�
	//subtract(image, m, dst);//����
	//imshow("��������:", dst);

	//�ӷ�
	//int w = image.cols;
	//int h = image.rows;
	//int dims = image.channels();
	//for (int row = 0; row < h; row++)
	//{
	//	for (int col = 0; col < w; col++)
	//	{
	//		Vec3b p1 = image.at<Vec3b>(row, col);
	//		Vec3b p2 = m.at<Vec3b>(row, col);
	//		//saturate_cast<uchar>��Ҫ��Ϊ�˷�ֹ��ɫ�������
	//		dst.at<Vec3b>(row, col)[0] = saturate_cast<uchar>(p1[0] + p2[0]);
	//		dst.at<Vec3b>(row, col)[1] = saturate_cast<uchar>(p1[1] + p2[1]);
	//		dst.at<Vec3b>(row, col)[2] = saturate_cast<uchar>(p1[2] + p2[2]);
	//	}
	//}

	/*saturate_cast<uchar>ԭ���������
if(data<0) 
        data=0; 
elseif(data>255) 
    data=255;*/

	waitKey(0);
}

int test02()
{
	Mat image2= imread("D://BingDownload//lena.png");//��ȡͼ��
	if (image2.empty())
	{
		cout << "��ȡ����" << endl;
		return -1;
	}
	
	imshow("image2", image2);//��ʾͼ��
	Mat imageROI(image2, Rect(0, 0, 100, 100));//�������Ȥ������ 0-100�� 0-100��
	waitKey(0);//��ͣ������ͼ����ʾ���ȴ���������

}
int main()
{
	test03();
	return 0;
}