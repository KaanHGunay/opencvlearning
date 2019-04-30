#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>

using namespace std;
using namespace cv;

#pragma region Blur filtresi tanýmlarý
float filtre[7][7] = {
	{1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1}
};

int filtreboyutu = 7;
#pragma endregion

#pragma region Median filtresi tanýmlarý
	Mat orgIm = imread("lena.jpg"), dst = imread("lena.jpg");
	int trackVal = 1;
	void track(int, void*) {
		if (trackVal % 2 == 1) {
			medianBlur(orgIm, dst, trackVal);
			cout << trackVal << endl;
			imshow("Median", dst);
		}
	}
#pragma endregion


int main() {
	#pragma region Blur
	// Bulanýklaþtýrma (Ortalama) Filtresi
	// Birlerden oluþan bir matris oluþturulur ve eleman sayýsý ile (4 x 4 matriste 1/16 ile) çarpýlýp orjinal resme uygulanýr.
	Mat orgIm = imread("lena.jpg");
	Mat dest;
	blur(orgIm, dest, Size(7, 7)); // Size blurlaþtýrma matrsinin boyutu
	// imshow("Blur", dest);

	// Kendi yazdýðýmýz bulanýklaþtýrma fonksiyonunu kullanma
	Mat bluredImage(orgIm.rows, orgIm.cols, CV_8UC3, Scalar(0, 0, 0));
	double k = 1.0 / (filtreboyutu * filtreboyutu), toplam_kanal1 = 0, toplam_kanal2 = 0, toplam_kanal3 = 0;
	for (int y = 0; y < orgIm.rows - filtreboyutu; y++) {
		for (int x = 0; x < orgIm.cols - filtreboyutu; x++) {
			for (int t = 0; t < filtreboyutu; t++) {
				for (int f = 0; f < filtreboyutu; f++) {
					toplam_kanal1 = toplam_kanal1 + orgIm.at<Vec3b>(y + t, x + f)[0] * filtre[t][f] * k;
					toplam_kanal2 = toplam_kanal2 + orgIm.at<Vec3b>(y + t, x + f)[1] * filtre[t][f] * k;
					toplam_kanal3 = toplam_kanal3 + orgIm.at<Vec3b>(y + t, x + f)[2] * filtre[t][f] * k;
				}
			}
			bluredImage.at<Vec3b>(y, x)[0] = toplam_kanal1;
			bluredImage.at<Vec3b>(y, x)[1] = toplam_kanal2;
			bluredImage.at<Vec3b>(y, x)[2] = toplam_kanal3;

			toplam_kanal1 = 0;
			toplam_kanal2 = 0;
			toplam_kanal3 = 0;
		}
	}

	// imshow("FuncBlur", bluredImage);
	// waitKey(0);
	#pragma endregion

	#pragma region Median (Orta) Filtre / Gürültü yok edici
	// Algoritma matriste bulunan gürültüyü yok etmek için 3 x 3 matrisin deðerlerini küçükten büyüye sýralayýp
	// Matrisin ortasýna bu sýraralamýnýn ortasýnda ki sayý yazýlarak gerçekleþtirilir.
	orgIm = imread("lena.jpg");
	namedWindow("Track", WINDOW_AUTOSIZE);
	createTrackbar("TrackBar", "Track", &trackVal, 100, track);
	imshow("Image", orgIm);
	imshow("Dest", dst);
	waitKey(0);
	#pragma endregion

	return 0;
}