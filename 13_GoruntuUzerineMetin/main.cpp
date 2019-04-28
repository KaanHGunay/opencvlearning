#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
	//Mat image(500, 500, CV_8UC3, Scalar(255, 0, 0));
	Mat image = imread("lena.jpg");

	// image -> Yazý yazýlacak resim
	// Test -> Yazýlacak metin
	// Point(x, y) -> Yazýlacak yer
	// FONT_HERSHEY_PLAIN -> Yazý tipi
	// 3 -> Yazýnýn büyüklüðü
	// Scalar(x, y, z) -> Yazýnýn rengi
	// 4 -> Yazýnýn kalýnlýðý
 	putText(image, "Test", Point(50, 50), FONT_HERSHEY_PLAIN, 3, Scalar(0, 255, 0), 4);
	imshow("Image", image);

	waitKey(0);
	return 0;
}