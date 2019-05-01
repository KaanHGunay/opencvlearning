#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
	Mat orgIm = imread("lena.jpg"), dst, erosion, dilation, open, close, tophet, gradient;
	cvtColor(orgIm, dst, COLOR_BGR2GRAY);
	threshold(dst, dst, 90, 255, THRESH_BINARY);

	erode(dst, erosion, getStructuringElement(MORPH_RECT, Size(3, 3)));
	dilate(dst, dilation, getStructuringElement(MORPH_RECT, Size(3, 3)));

	imshow("Erosion", erosion);
	imshow("Dilation", dilation);
	imshow("Org", orgIm);

	// Opening Ýþlemi - Görüntü düzeltme
	Mat element = getStructuringElement(MORPH_RECT, Size(7, 7));
	morphologyEx(dst, open, MORPH_OPEN, element, Point(-1, -1), 1); // Opening Ýþlemi Point belirtmemek için -1 -1 parametreleri verildi, 1 kere erote ve dilate iþlemi yapýlacak
	morphologyEx(dst, close, MORPH_CLOSE, element, Point(-1, -1), 1); // Closing iþlemi
	morphologyEx(dst, tophet, MORPH_TOPHAT, element, Point(-1, -1), 1); // Tophet iþlemi - Yuvarlaklarý bulma
	morphologyEx(dst, gradient, MORPH_GRADIENT, element, Point(-1, -1), 1); // Gradient iþlemi - Ana hatlarý bulma

	imshow("Open", open);
	imshow("Close", close);
	imshow("Tophet", tophet);
	imshow("Gradient", gradient);

	waitKey(0);
	return 0;
}