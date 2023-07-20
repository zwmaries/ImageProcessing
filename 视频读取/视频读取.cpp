#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

void video_demo(Mat& image)
{
	VideoCapture capture(0);
	//读取指定视频
	/*VideoCapture capture("C:/Users/pc-/Desktop/WeChat_20230719100517.mp4");
	
	int frame_width = capture.get(CAP_PROP_FRAME_WIDTH);
	int frame_height = capture.get(CAP_PROP_FRAME_HEIGHT);
	int count = capture.get(CAP_PROP_FRAME_COUNT);
	double fps = capture.get(CAP_PROP_FPS);
	cout << "frame width:" << frame_width << endl;
	cout << "frame height:" << frame_height << endl;
	cout << "Number of Frames:" << count << endl;
	cout << "fps:" << fps << endl;
	//写入test.mp4中
	VideoWriter writer("C:/Users/pc-/Desktop/test.mp4", capture.get(CAP_PROP_FOURCC), fps, Size(frame_width, frame_height), true);*/
	Mat frame;
	while (true)
	{
		capture.read(frame);
		flip(frame, frame, 1);
		if (frame.empty())
		{
			break;
		}
		imshow("frame", frame);
		int c = waitKey(10);
		if (c == 27)//退出
		{
			break;
		}
	}

	//release
	capture.release();
}

int main()
{
	Mat image = imread("D://BingDownload//tiankong.jpg");
	video_demo(image);
	waitKey(0);
	return 0;
}