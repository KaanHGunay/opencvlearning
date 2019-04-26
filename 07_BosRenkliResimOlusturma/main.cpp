#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat newSize; // Boyut de�i�tirmeden sonra atama yap�lacak matris

int main() {
	Mat crtim(240, 240, CV_8UC3, Scalar(54, 0, 34)); // Renkli Resim Olu�turma (Boyut_Sat�r, Boyut_s�tun, Foto�raf_Tipi (8 Bitlik 3 Kanall�), Renk)
	Mat crtgrey(240, 240, CV_8UC1, Scalar(150)); // Siyah-beyaz Resim Olu�turma

	namedWindow("Resim1", WINDOW_AUTOSIZE);
	namedWindow("Resim2", WINDOW_AUTOSIZE);

	imshow("Resim1", crtim);
	imshow("Resim2", crtgrey);
	waitKey(0);
	destroyWindow("Resim1");
	destroyWindow("Resim2");
	return 0;
}