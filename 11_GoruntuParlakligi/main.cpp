#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat c;

void Parlaklik(Mat input, Mat output, int dept, float alpha, float beta) {
	if (dept == -1) { // Çok kanallý/renkli resim ise
		for (int i = 0; i < input.rows; i++) { // Tüm satýrlarý gez
			for (int j = 0; j < input.cols; j++) { // Tüm sütunlarý gez				
				for (int k = 0; k < 3; k++) // Üç kanal (BGR - Blue Green Red) için ayrý ayrý kontras deðiþimi
				{
					if (input.at<Vec3b>(i, j)[k] * alpha + beta > 255) {
						input.at<Vec3b>(i, j)[k] = 255;
					}
					else if (input.at<Vec3b>(i, j)[k] * alpha + beta < 0) {
						input.at<Vec3b>(i, j)[k] = 0;
					}
					else {
						input.at<Vec3b>(i, j)[k] = input.at<Vec3b>(i, j)[k] * alpha + beta;
					}
				}
			}
		}
	}
	else if (dept == 1) {
		cvtColor(input, input, COLOR_BGR2GRAY); // Resmin griye çevrilmesi
		for (int i = 0; i < input.rows; i++) {
			for (int j = 0; j < input.cols; j++) {
				if (input.at<uchar>(i, j) * alpha + beta > 255) {
					input.at<uchar>(i, j) = 255;
				}
				else if (input.at<uchar>(i, j) * alpha + beta < 0) {
					input.at<uchar>(i, j) = 0;
				}
				else {
					input.at<uchar>(i, j) = input.at<uchar>(i, j) * alpha + beta;
				}
			}
		}
	}
	else {
		return;
	}

	c = input;
}

int main() {
	#pragma region Hazýr Fonksiyon
	/*
	// Parlaklýk Ayarlama
	Mat orgIm = imread("lena.jpg");
	Mat lowDest, highDest;

	// highDest -> çýkýþ matrisi
	// -1 -> orjinal resme dokunma
	// 1 -> piksellere uygulanan katsayý
	// 200 -> piksellere uygulanan ekleme

	orgIm.convertTo(highDest, -1, 1, 100);
	orgIm.convertTo(lowDest, -1, 1, -100);

	imshow("High", highDest);
	imshow("Low", lowDest);
	imshow("orginal", orgIm);

	waitKey(0);*/
	#pragma endregion

	Mat orgIm = imread("lena.jpg");
	Parlaklik(orgIm, c, -1, 1, 200);

	imshow("Parlak", c);
	waitKey(0);
	return 0;
}
