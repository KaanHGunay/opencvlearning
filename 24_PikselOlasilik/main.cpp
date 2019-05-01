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
	
	waitKey(0);
	return 0;
}
