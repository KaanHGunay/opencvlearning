#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
	#pragma region SiyahBeyazCevirme
	// Siyah Beyaz Formata Çevirme
	Mat orgIm = imread("lena.jpg");
	Mat grayIm;

	cvtColor(orgIm, grayIm, COLOR_BGR2GRAY); // Renkli resmi siyah beyaz formata çevirme

	imshow("Resim", grayIm); // Resmi gösterme
	waitKey(0);
	#pragma endregion

	#pragma region BinaryCevirme
	// Binary Formata Çevirme - Ýþlem Kolaylýðý için binary format önemli
	Mat orgIm2 = imread("lena.jpg");
	Mat grayIm2, binImg;
	cvtColor(orgIm2, grayIm2, COLOR_BGR2GRAY); // önce resmi siyah beyaz formata çeviriyoruz.

	// grayImg2 -> Input image
	// binImg -> Output image
	// 30 -> threshold value - deðerin üstü sonraki parametreye çýkarýlacak
	// 255 -> threshold deðerinin üstünde kalan deðerlerin eþitlenme sayýsý
	// THRESH_BINARY -> yapýlacak iþlem
	threshold(grayIm2, binImg, 100, 255, THRESH_BINARY);

	imshow("Grey", grayIm2);
	imshow("Binary", binImg);
	waitKey(0);
	#pragma endregion

	#pragma region TersiAlma
	// Resmin tersini alma iþlemi
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

	Mat rgbkanal[3]; // 3 Kanallý resim olduðu için 3 boyutlu matris tanýmlamasý
	split(orgImg4, rgbkanal); // Resmi kanallara ayýrma

	imshow("Red", rgbkanal[0]); // Kýrmýzý kanalýn görüntülenmesi
	imshow("Green", rgbkanal[1]); // Yeþil kanalýn görüntülenmesi
	imshow("Blue", rgbkanal[2]); // Mavi kanalýn görüntülenmesi

	// Kanallarý birleþririlmesi
	Mat dst;
	vector<Mat> kanallar; // Kanallarýn bulunduðu matris
	kanallar.push_back(rgbkanal[0]); 
	kanallar.push_back(rgbkanal[1]);
	kanallar.push_back(rgbkanal[2]);
	merge(kanallar, dst); // Kanallarýn birleþtirilerek matrise atanmasý
	imshow("Merge", dst);

	waitKey(0);
	#pragma endregion

	return 0;
}