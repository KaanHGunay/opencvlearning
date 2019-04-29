#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat orgIm = imread("lena.jpg");
void func(int, int, int, int, void*);
Point ptr1, ptr2;

int main() {
	namedWindow("Image", WINDOW_AUTOSIZE);
	setMouseCallback("Image", func, NULL);
	imshow("Image", orgIm);

	waitKey(0);
	return 0;
}

void func(int event, int x, int y, int flags, void* userdata) {
	if (event == EVENT_LBUTTONDOWN) {
		ptr1.x = x;
		ptr1.y = y;
	}

	if (event == EVENT_MOUSEMOVE && flags == EVENT_FLAG_LBUTTON) {
		ptr2.x = x;
		ptr2.y = y;

		Mat temp = Mat::zeros(orgIm.size(), CV_8UC3);
		rectangle(temp, ptr1, ptr2, Scalar(0, 255, 0), 4, 8, 0);
		temp = temp + orgIm;
		imshow("Cropped", temp);
	}

	if (event == EVENT_LBUTTONUP) {
		Rect crop;
		crop.x = ptr1.x;
		crop.y = ptr1.y;

		crop.width = ptr2.x - ptr1.x;
		crop.height = ptr2.y - ptr1.y;

		Mat lastImage = orgIm(crop);
		imshow("LastImage", lastImage);
	}
}