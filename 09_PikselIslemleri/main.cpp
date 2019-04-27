#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
	#pragma region RenkliResimPikselDegerleri
	Mat orgIm = imread("lena.jpg");
	int blue = orgIm.at<Vec3b>(100, 200)[0]; // Resmin belirtilen noktadaki mavi renk deðeri
	int green = orgIm.at<Vec3b>(100, 200)[1]; // Resmin belirtilen noktadaki yeþil renk deðeri
	int red = orgIm.at<Vec3b>(100, 200)[2]; // Resmin belirtilen noktadaki kýrmýzý renk deðeri

	cout << "Mavi: " << blue << endl;
	cout << "Yesil: " << green << endl;
	cout << "Kirmizi: " << red << endl;
	#pragma endregion


	#pragma region GriResimPikselDegerleri
	Mat orgImg2 = imread("lena.jpg");
	Mat dstImg;
	resize(orgImg2, dstImg, Size(200, 200)); // Tekrar boyutlandýrma
	cvtColor(dstImg, dstImg, COLOR_BGR2GRAY); // Siyah Beyaza Çevirme
	int yogunluk = dstImg.at<uchar>(100, 100); // Siyah beyaz resimden yoðunluk deðerini alma
	cout << "Yogunluk: " << yogunluk << endl;
	#pragma endregion

	return 0;
}