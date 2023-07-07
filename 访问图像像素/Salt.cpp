#include "Salt.h"
#include <iostream>

void Salt(Mat image, int n)
{
	//随机数生成器
	default_random_engine generater;
	uniform_int_distribution<int>randomRow(0, image.rows - 1);
	uniform_int_distribution<int>randomCol(0, image.cols - 1);

	int i, j;
	for (int k = 0; k < n; ++k)
	{
		i = randomRow(generater);
		j = randomCol(generater);
		if (image.channels() == 1)
		{
			image.at<uchar>(i, j) = 255;
		}
		else if (image.channels() == 3)
		{
			image.at<Vec3b>(i, j)[0] = 255;
			image.at<Vec3b>(i, j)[1] = 255;
			image.at<Vec3b>(i, j)[2] = 255;
		}
	}
}