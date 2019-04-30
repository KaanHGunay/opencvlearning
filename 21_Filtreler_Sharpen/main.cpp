#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat orgIm = imread("lena.jpg");
Mat dest;
int trackVal = 1;
void track(int, void*) {
	addWeighted(orgIm, trackVal / 7.0, dest, -0.5, 0, dest);
	imshow("Image", dest);
}

int main() {
	resize(orgIm, orgIm, Size(500, 500));
	GaussianBlur(orgIm, dest, Size(3, 3), 11);
	namedWindow("TrackBarWindow", WINDOW_AUTOSIZE);
	createTrackbar("TrackBar", "TrackBarWindow", &trackVal, 100, track);

	waitKey(0);
	return 0;
}