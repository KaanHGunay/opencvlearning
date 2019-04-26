#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat newSize; // Boyut deðiþtirmeden sonra atama yapýlacak matris

int main() {
	Mat img1 = imread("lena.jpg");
	Mat img2 = imread("bursa.jpg");

	resize(img2, newSize, Size(img1.cols, img1.rows)); // Ýkinci resmi birinci resmin boyutlarýna getirme

	namedWindow("Resim1", WINDOW_AUTOSIZE);
	namedWindow("Resim2", WINDOW_AUTOSIZE);
	namedWindow("Resim3", WINDOW_AUTOSIZE);

	imshow("Resim1", img1);
	imshow("Resim2", img2);
	imshow("Resim3", newSize);

	waitKey(0);
	destroyWindow("Resim1");
	destroyWindow("Resim2");
	destroyWindow("Resim3");
	
	return 0;
}