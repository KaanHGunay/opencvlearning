#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
	Mat orgIm = imread("lena.jpg");
	cvtColor(orgIm, orgIm, COLOR_BGR2GRAY);
	int dizi[255] = { }; // Renklerin olasýlýk deðerlerini hesaplama adýna 255 lik bir dizi oluþturulur. (Siyah beyaz fotoðraf)

	for (int i = 0; i < orgIm.cols; i++) {
		for (int j = 0; j < orgIm.rows; j++) {
			for (int k = 0; k < 255; k++) {
				if (orgIm.at<uchar>(j, i) == k) {
					dizi[k]++;
				}
			}
		}
	}

	for (int i = 0; i < 255; i++) {
		cout << i << " => " << dizi[i] << endl;
	}

	// Grafik çizme
	Mat grafik(800, 1200, CV_8UC3, Scalar(0, 0, 0));
	for (int i = 0; i < 255; i++) {
		line(grafik, Point(i * 1200 / 255, 800), Point(i * 1200 / 255, 800 - dizi[i] / 2), Scalar(50, i, dizi[i]), 5, 8, 0); // dizi[i] / 30 tanýmý grafiðe sýðdarmak için yapýlmýþ. Ayný oranda küçülmeleri saðlanmaþtýr.
	}
	imshow("Grafik", grafik);

	waitKey(0);
	return 0;
}
