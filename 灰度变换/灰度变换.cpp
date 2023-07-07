#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

//�Ҷȷ�ת
int GrayChange()
{
	Mat image1, output_image, image1_gray;//�������롢������Ҷ�ͼ��
	image1 = imread("D://BingDownload//lena.png");
	if (image1.empty())
	{
		cout << "��ȡ����" << endl;
		return -1;
	}

	cvtColor(image1, image1_gray, COLOR_BGR2GRAY);//�ҶȻ�
	imshow(" image1_gray", image1_gray);
	output_image = image1_gray.clone();//���ƻҶ�ͼ��
	for (int i = 0; i < image1_gray.rows; i++)
	{
		for (int j = 0; j < image1_gray.cols; j++)
		{
			output_image.at<uchar>(i, j) = 255 - image1_gray.at<uchar>(i, j);//�Ҷȷ�ת

		}
	}
	imshow("output_image", output_image);//��ʾ��תͼ��

}

//����ת��
int LogChange()
{
	Mat image1, output_image, image1_gray;   //��������ͼ�����ͼ�񣬻Ҷ�ͼ��
	image1 = imread("D://BingDownload//lena.png");  //��ȡͼ��
	if (image1.empty())
	{
		cout << "��ȡ����" << endl;
		return -1;
	}

	cvtColor(image1, image1_gray, COLOR_BGR2GRAY);  //�ҶȻ�
	imshow(" image1_gray", image1_gray);   //��ʾ�Ҷ�ͼ��

	output_image = image1_gray.clone();
	for (int i = 0; i < image1_gray.rows; i++)
	{
		for (int j = 0; j < image1_gray.cols; j++)
		{
			output_image.at<uchar>(i, j) = 6 * log((double)(image1_gray.at<uchar>(i, j)) + 1);  //�����任 s=6*log(r+1)
		}
	}
	normalize(output_image, output_image, 0, 255, NORM_MINMAX);  //ͼ���һ����ת��0~255��Χ��
	convertScaleAbs(output_image, output_image);  //��������ת����CV_8U
	imshow(" output_image", output_image);  //��ʾ�任ͼ��
}


int MiluChange()
{
	Mat image1, output_image, image1_gray;   //��������ͼ�����ͼ�񣬻Ҷ�ͼ��
	image1 = imread("D://BingDownload//lena.png");  //��ȡͼ��
	if (image1.empty())
	{
		cout << "��ȡ����" << endl;
		return -1;
	}

	cvtColor(image1, image1_gray, COLOR_BGR2GRAY);  //�ҶȻ�
	imshow(" image1_gray", image1_gray);   //��ʾ�Ҷ�ͼ��

	output_image = image1_gray.clone();
	for (int i = 0; i < image1_gray.rows; i++)
	{
		for (int j = 0; j < image1_gray.cols; j++)
		{
			output_image.at<uchar>(i, j) = 6 * pow((double)(image1_gray.at<uchar>(i, j)) , 0.8);  //���ɱ任 s=6*r^0.5  ��ָ��С��1ʱ��ǿ����ϸ�ڣ���ָ������1ʱ��ǿ����ϸ��
		}
	}
	normalize(output_image, output_image, 0, 255, NORM_MINMAX);  //ͼ���һ����ת��0~255��Χ��
	convertScaleAbs(output_image, output_image);  //��������ת����CV_8U
	imshow(" output_image", output_image);  //��ʾ�任ͼ��
}

int main()
{
	MiluChange();
	waitKey(0);
	return 0;
}