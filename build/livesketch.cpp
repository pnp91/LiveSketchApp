#include "livesketch.h"

void livesketch::pencilSketcher()
{
	cv::VideoCapture cap(0);
	cv::Mat frame;
	cv::Mat grayscale_frame;

	if (!cap.isOpened()) {
		cout << "Video not captured" << endl;
		return;
	}


	while (cap.isOpened())
	{
		if (cap.read(frame))
		{
			cv::cvtColor(frame, grayscale_frame, cv::COLOR_BGR2GRAY);
			Mat grayscale_frame_blurred;
			cv::GaussianBlur(grayscale_frame, grayscale_frame_blurred, Size(5, 5), 0);
			Mat gray_edges;
			cv::Canny(grayscale_frame_blurred, gray_edges, 10, 70, 3);
			Mat sketch_image;
			cv::threshold(gray_edges, sketch_image, 70, 255, THRESH_BINARY_INV);

			imshow("Sketch", sketch_image);

		}
		if (waitKey(1) == 13)
		{
			break;
		}
	}

}