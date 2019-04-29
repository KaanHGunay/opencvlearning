#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat orgIm = imread("lena.jpg");
void func(int, int, int, int, void*);

int main() {	
	namedWindow("Image", WINDOW_AUTOSIZE);
	setMouseCallback("Image", func, NULL);
	imshow("Image", orgIm);

	waitKey(0);
	return 0;
}

void func(int event, int x, int y, int flags, void* userdata) {
	if (event == EVENT_MOUSEMOVE) {
		int blue = orgIm.at<Vec3b>(y, x)[0];
		int green = orgIm.at<Vec3b>(y, x)[1];
		int red = orgIm.at<Vec3b>(y, x)[2];

		cout << "Blue => " << blue << " - " << "Green => " << green << " - " << "Red => " << red << endl;
	}
}