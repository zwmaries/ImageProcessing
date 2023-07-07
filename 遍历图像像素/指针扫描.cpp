#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

//ָ��ɨ��
int nodesm()
{
	Mat image1, output_image;//��������ͼ������ͼ��
	image1 = imread("D://BingDownload//lena.png");
	if (image1.empty())
	{
		cout << "��ȡ����" << endl;
		return -1;
	}
	output_image = Mat(image1.size(), image1.type());//�������ͼ���С
	output_image = image1.clone();//��¡ԭͼ����ֵ

	int rows = image1.rows;//ԭͼ����
	int stepx = image1.channels();//ԭͼͨ����
	int cols = (image1.cols) * image1.channels();//����������

	for (int row = 1; row < (rows - 1); row++)   //���б���
	{
		const uchar* previous = image1.ptr<uchar>(row - 1);  //ԭͼ��һ��ָ��
		const uchar* current = image1.ptr<uchar>(row);       //ԭͼ��ǰ��ָ��
		const uchar* next = image1.ptr<uchar>(row + 1);      //ԭͼ��һ��ָ��
		uchar* output = output_image.ptr<uchar>(row);        //���ͼ��ǰ��ָ��

		for (int col = stepx; col < (cols - stepx); col++)  //���б���
		{
			output[col] = saturate_cast<uchar>(5 * current[col] - (previous[col] + current[col - stepx] + current[col + stepx] + next[col]));
			//saturate_cast<uchar>(a)����a��0��255ʱ���a����aС��0���0����a����255���255����֤a��ֵ��0~255֮��
		}
	}

	imshow("image1", image1);
	imshow("output_image", output_image);
}

//�Դ�������� filter2D
int filter2()
{
	Mat image1, output_image;
	image1 = imread("D://BingDownload//lena.png");
	if (image1.empty())
	{
		cout << "��ȡ����" << endl;
		return -1;
	}
	Mat kernel = (Mat_<char>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);//�����˲���
	filter2D(image1, output_image, image1.depth(), kernel);

	imshow("image1", image1);
	imshow("output_image", output_image);

}
int main()
{
	
	filter2();
	waitKey(0);  //��ͣ������ͼ����ʾ���ȴ���������
	return 0;
}