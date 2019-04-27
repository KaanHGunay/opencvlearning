#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat c;
void Kontrast(Mat, Mat, int, float); // Kontrast Fonksiyonu tan�mlama

int main() {
	#pragma region Haz�r Kontrast Fonksiyonu
	/*Mat img = imread("lena.jpg");
	Mat newHight, newLow;
	
	// newHight -> ��k�� matrisi
	// -1 -> Foto�rafta de�i�iklik yapma
	// 2 -> Her pikselin �arp�lma katsay�s�
	// 0 -> Her piksele eklenen sabit
	img.convertTo(newHight, -1, 2, 0);
	img.convertTo(newLow, -1, 0.2, 0);

	imshow("Original", img);
	imshow("Hight", newHight);
	imshow("Low", newLow);
	waitKey(0);*/
	#pragma endregion

	#pragma region Kontras Fonksiyonu Olu�turma
	Mat img2 = imread("lena.jpg");
	Mat dest2;
	Kontrast(img2, dest2, -1, 0.2);
	imshow("Resim", c);
	imshow("original", img2);
	waitKey(0);
	#pragma endregion

	return 0;
}

void Kontrast(Mat input, Mat output, int dept, float alpha) {
	if (dept == -1) { // �ok kanall�/renkli resim ise
		for (int i = 0; i < input.rows; i++) { // T�m sat�rlar� gez
			for (int j = 0; j < input.cols; j++) { // T�m s�tunlar� gez				
				for (int k = 0; k < 3; k++) // �� kanal (BGR - Blue Green Red) i�in ayr� ayr� kontras de�i�imi
				{
					if (input.at<Vec3b>(i, j)[k] * alpha > 255) {
						input.at<Vec3b>(i, j)[k] = 255;
					}
					else {
						input.at<Vec3b>(i, j)[k] = input.at<Vec3b>(i, j)[k] * alpha;
					}
				}
			}
		}
	}
	else if (dept == 1) {
		cvtColor(input, input, COLOR_BGR2GRAY); // Resmin griye �evrilmesi
		for (int i = 0; i < input.rows; i++) {
			for (int j = 0; j < input.cols; j++) {
				if (input.at<uchar>(i, j) * alpha > 255) {
					input.at<uchar>(i, j) = 255;
				}
				else {
					input.at<uchar>(i, j) = input.at<uchar>(i, j) * alpha;
				}
			}
		}
	}
	else {
		return;
	}

	c = input;
}
