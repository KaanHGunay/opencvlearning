#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
	#pragma region RenkliResimPikselDegerleri
	Mat orgIm = imread("lena.jpg");
	int blue = orgIm.at<Vec3b>(100, 200)[0]; // Resmin belirtilen noktadaki mavi renk de�eri
	int green = orgIm.at<Vec3b>(100, 200)[1]; // Resmin belirtilen noktadaki ye�il renk de�eri
	int red = orgIm.at<Vec3b>(100, 200)[2]; // Resmin belirtilen noktadaki k�rm�z� renk de�eri

	cout << "Mavi: " << blue << endl;
	cout << "Yesil: " << green << endl;
	cout << "Kirmizi: " << red << endl;
	#pragma endregion


	#pragma region GriResimPikselDegerleri
	Mat orgImg2 = imread("lena.jpg");
	Mat dstImg;
	resize(orgImg2, dstImg, Size(200, 200)); // Tekrar boyutland�rma
	cvtColor(dstImg, dstImg, COLOR_BGR2GRAY); // Siyah Beyaza �evirme
	int yogunluk = dstImg.at<uchar>(100, 100); // Siyah beyaz resimden yo�unluk de�erini alma
	cout << "Yogunluk: " << yogunluk << endl;
	#pragma endregion

	return 0;
}