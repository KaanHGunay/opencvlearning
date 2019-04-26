#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
	#pragma region SiyahBeyazCevirme
	// Siyah Beyaz Formata �evirme
	Mat orgIm = imread("lena.jpg");
	Mat grayIm;

	cvtColor(orgIm, grayIm, COLOR_BGR2GRAY); // Renkli resmi siyah beyaz formata �evirme

	imshow("Resim", grayIm); // Resmi g�sterme
	waitKey(0);
	#pragma endregion

	#pragma region BinaryCevirme
	// Binary Formata �evirme - ��lem Kolayl��� i�in binary format �nemli
	Mat orgIm2 = imread("lena.jpg");
	Mat grayIm2, binImg;
	cvtColor(orgIm2, grayIm2, COLOR_BGR2GRAY); // �nce resmi siyah beyaz formata �eviriyoruz.

	// grayImg2 -> Input image
	// binImg -> Output image
	// 30 -> threshold value - de�erin �st� sonraki parametreye ��kar�lacak
	// 255 -> threshold de�erinin �st�nde kalan de�erlerin e�itlenme say�s�
	// THRESH_BINARY -> yap�lacak i�lem
	threshold(grayIm2, binImg, 100, 255, THRESH_BINARY);

	imshow("Grey", grayIm2);
	imshow("Binary", binImg);
	waitKey(0);
	#pragma endregion

	#pragma region TersiAlma
	// Resmin tersini alma i�lemi
	Mat orgIm3 = imread("lena.jpg");
	Mat negImg;
	bitwise_not(orgIm3, negImg);

	imshow("Org", orgIm3);
	imshow("Negative", negImg);
	waitKey(0);
	#pragma endregion
	
	#pragma region MergeSplitIleKanalAyirma
	Mat orgImg4 = imread("lena.jpg");
	imshow("Original", orgImg4);

	Mat rgbkanal[3]; // 3 Kanall� resim oldu�u i�in 3 boyutlu matris tan�mlamas�
	split(orgImg4, rgbkanal); // Resmi kanallara ay�rma

	imshow("Red", rgbkanal[0]); // K�rm�z� kanal�n g�r�nt�lenmesi
	imshow("Green", rgbkanal[1]); // Ye�il kanal�n g�r�nt�lenmesi
	imshow("Blue", rgbkanal[2]); // Mavi kanal�n g�r�nt�lenmesi

	// Kanallar� birle�ririlmesi
	Mat dst;
	vector<Mat> kanallar; // Kanallar�n bulundu�u matris
	kanallar.push_back(rgbkanal[0]); 
	kanallar.push_back(rgbkanal[1]);
	kanallar.push_back(rgbkanal[2]);
	merge(kanallar, dst); // Kanallar�n birle�tirilerek matrise atanmas�
	imshow("Merge", dst);

	waitKey(0);
	#pragma endregion

	return 0;
}