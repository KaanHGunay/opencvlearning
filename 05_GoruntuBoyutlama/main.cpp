#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
	Mat orgImg = imread("lena.jpg");
	int sutun = orgImg.cols; // S�tun say�s�na ula�ma
	int satir = orgImg.rows; // sat�r say�s�na ula�ma

	cout << sutun << endl << satir << endl;

	namedWindow("Resim", WINDOW_AUTOSIZE);
	imshow("Resim", orgImg);
	waitKey(0);
	destroyWindow("Resim");

	return 0;
}