#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat orgIm = imread("lena.jpg");
int sayac = 0;
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
		sayac++;
		if (sayac == 1) {
			ptr1.x = x;
			ptr1.y = y;
		}
		else if (sayac == 2) {
			ptr2.x = x;
			ptr2.y = y;
			line(orgIm, ptr1, ptr2, Scalar(0, 255, 0), 2, 8, 0);
			imshow("Image", orgIm);
			sayac = 0;
		}
	}
}