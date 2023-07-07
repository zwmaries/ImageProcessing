#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;
int main()
{
	Mat image, image_gray, hist;//��������ͼ�񣬻Ҷ�ͼ��ֱ��ͼ
	image = imread("D://BingDownload//lena.png");
	if (image.empty())
	{
		cout << "��ȡ����" << endl;
		return -1;
	}
	cvtColor(image, image_gray, COLOR_BGR2GRAY);//�ҶȻ�
	imshow("image_gray", image_gray);//��ʾ�Ҷ�ͼ��

	//��ȡͼ��ֱ��ͼ
	int histsize = 256;
	float ranges[] = { 0,256 };
	const float* histRanges = { ranges };
	calcHist(&image_gray, 1, 0, Mat(), hist, 1, &histsize, &histRanges, true, false);

	//����ֱ��ͼ��ʾͼ��
	int hist_h = 300;//ֱ��ͼ��ͼ��ĸ�
	int hist_w = 512;//ֱ��ͼ��ͼ��Ŀ�
	int bin_w = hist_w / histsize;//ֱ��ͼ�ĵȼ�
	Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(0, 0, 0));//����ֱ��ͼ��ʾ��ͼ��

	//���Ʋ���ʾֱ��ͼ
	normalize(hist, hist, 0, hist_h, NORM_MINMAX, -1, Mat());//��һ��ֱ��ͼ
	for (int i = 1; i < histsize; i++)
	{
		line(histImage, Point((i - 1) * bin_w, hist_h - cvRound(hist.at<float>(i - 1))), 
			Point((i)*bin_w, hist_h - cvRound(hist.at<float>(i))), Scalar(255, 0, 0), 2, 8, 0);
	}
	imshow("histImage", histImage);

	waitKey(0);
	return 0;
}