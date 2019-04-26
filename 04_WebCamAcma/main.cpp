#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
	VideoCapture cap(0); // Webcamin alýnmasý

	if (!cap.open(0)) return -1;

	while (true) {
		Mat frame;
		cap >> frame; // Her frame'i matrise atma

		if (waitKey(30) == 27 || frame.empty()) { 
			break;
		}

		imshow("Video", frame);
	}

	return 0;
}