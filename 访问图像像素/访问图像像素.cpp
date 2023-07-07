#include <iostream>
#include <opencv2/opencv.hpp>
#include "Salt.h"
using namespace std;
using namespace cv;

int main()
{
	Mat image1 = imread("D://BingDownload//lena.png");
	if (image1.empty())
	{
		cout << "¶ÁÈ¡´íÎó" << endl;
		return -1;
	}
	imshow("image1", image1);//ÏÔÊ¾Ô­Í¼Ïñ
	Salt(image1, 5000);//¼ÓÈë5000¸öÔëÉùµã
	imshow("image2", image1);//ÏÔÊ¾ÔëÉùÍ¼Ïñ
	waitKey(0);
	return 0;
}