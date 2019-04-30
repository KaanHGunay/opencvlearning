#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
	Mat orgIm = imread("lena.jpg"), grayIm, dst, abs_dst;
	resize(orgIm, orgIm, Size(500, 500));
	GaussianBlur(orgIm, orgIm, Size(3, 3), 7);
	cvtColor(orgIm, grayIm, COLOR_BGR2GRAY);
	Laplacian(grayIm, dst, CV_16S, 5);
	convertScaleAbs(dst, abs_dst); // Laplacian fonksiyonundan eksi deðerler dönmesi nedeniyle mutlak deðer alma iþlemi
	imshow("Image", abs_dst);

	waitKey(0);
	return 0;
}