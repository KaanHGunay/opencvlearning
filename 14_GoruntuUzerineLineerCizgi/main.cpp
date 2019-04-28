#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>

using namespace std;
using namespace cv;

// �izgi �ekme fonksiyonunun tan�mlanmas�
void cizgi_cek(Mat, Point, Point, Scalar, int);

int main() {
	Mat orgImg = imread("lena.jpg");
	// orgImg -> Orjinal resim 
	// Point(100, 50) -> Ba�lang�� noktas�
	// Point(200, 75) -> Biti� Noktas�
	// Scalar(75, 25, 90) -> �izgi rengi
	// 3 -> �izgi kal�nl���
	// LINE_AA -> �izgi tipi
	// 0 -> Kayd�rma de�eri 
	line(orgImg, Point(100, 50), Point(200, 75), Scalar(75, 25, 90), 3, LINE_AA, 0);
	imshow("Image", orgImg);

	// Kendi tan�mlad���m�z �izgi �ekme fonksiyonu
	cizgi_cek(orgImg, Point(150, 50), Point(250, 50), Scalar(75, 25, 90), 3);
	imshow("Image2", orgImg);

	// Resme daire �izme
	circle(orgImg, Point(30, 30), 30, Scalar(0, 0, 255), 3, LINE_AA, 0);
	imshow("Image3", orgImg);

	waitKey(0);
	return 0;
}

void cizgi_cek(Mat orgImg, Point startPoint, Point endPoint, Scalar color, int thickness) {
	for (int i = startPoint.x; i < endPoint.x; i++) {
		for (int j = startPoint.y; j < startPoint.x + thickness; j++) {
			orgImg.at<Vec3b>(j, i)[0] = color[0];
			orgImg.at<Vec3b>(j, i)[1] = color[1];
			orgImg.at<Vec3b>(j, i)[2] = color[2];
		}
	}
}
