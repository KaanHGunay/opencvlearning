#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
	Mat orgIm = imread("lena.jpg");
	Mat destIm;

	bilateralFilter(orgIm, destIm, 15, 100, 100);
	imshow("OrgImage", orgIm);
	imshow("DestImage", destIm);
	waitKey(0);
	return 0;
}