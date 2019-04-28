#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
	//Mat image(500, 500, CV_8UC3, Scalar(255, 0, 0));
	Mat image = imread("lena.jpg");

	// image -> Yaz� yaz�lacak resim
	// Test -> Yaz�lacak metin
	// Point(x, y) -> Yaz�lacak yer
	// FONT_HERSHEY_PLAIN -> Yaz� tipi
	// 3 -> Yaz�n�n b�y�kl���
	// Scalar(x, y, z) -> Yaz�n�n rengi
	// 4 -> Yaz�n�n kal�nl���
 	putText(image, "Test", Point(50, 50), FONT_HERSHEY_PLAIN, 3, Scalar(0, 255, 0), 4);
	imshow("Image", image);

	waitKey(0);
	return 0;
}