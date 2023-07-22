#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>

using namespace std;
using namespace cv;

void face_detection_demo()
{
	string root_dir = "D:/opencv/opencv/sources/samples/dnn/face_detector/";
	dnn::Net net=dnn::readNetFromTensorflow(root_dir + "opencv_face_detector_uint8.pb", root_dir + "opencv_face_detector.pbtxt");
	VideoCapture capture(0);
	Mat frame;
	while (true)
	{
		capture.read(frame);
		flip(frame, frame, 1);
		if (frame.empty())
		{
			break;
		}
		Mat blob = dnn::blobFromImage(frame, 1.0, Size(300, 300), Scalar(104, 177, 123), false, false);
		net.setInput(blob);
		Mat probs = net.forward();
		Mat detectionMat(probs.size[2], probs.size[3], CV_32F, probs.ptr<float>());
		//�������
		for (int i = 0; i < detectionMat.rows; i++)
		{
			float confidence = detectionMat.at<float>(i, 2);
			if (confidence > 0.5)
			{
				int x1 = static_cast<int>(detectionMat.at<float>(i, 3) * frame.cols);
				int y1 = static_cast<int>(detectionMat.at<float>(i, 4) * frame.rows);
				int x2 = static_cast<int>(detectionMat.at<float>(i, 5) * frame.cols);
				int y2 = static_cast<int>(detectionMat.at<float>(i, 6) * frame.rows);
				Rect box(x1, y1, x2 - x1, y2 - y1);
				rectangle(frame, box, Scalar(0, 0, 255), 2, 8, 0);
			}
		}
		imshow("���������ʾ", frame);
		int c = waitKey(1);
		if (c == 27)//�˳�
		{
			break;
		}
	}
	capture.release();
}

int main()
{
	face_detection_demo();
	waitKey(0);
	return 0;
}