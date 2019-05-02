#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main() {
	Mat orgIm = imread("lena.jpg"), dst;
	Canny(orgIm, dst, 50, 200, 3); // Kenar tespit
	cvtColor(dst, dst, COLOR_GRAY2BGR); // Renkli resme çevir
	vector<Vec2f> lines;
	HoughLines(dst, lines, 1, CV_PI / 180, 150); // Çizgileri bul - CV_PI / 180 tüm açıların tespiti için

	for (size_t i = 0; i < lines.size(); i++) {
		float rho = lines[i][0], theta = lines[i][1];
		Point ptr1, ptr2;
		double a = cos(theta), b = sin(theta);
		double x0 = a * rho, y0 = b * rho;

		ptr1.x = cvRound(x0 + 1000 * (-b));
		ptr1.y = cvRound(y0 + 1000 * a);
		ptr2.x = cvRound(x0 - 1000 * (-b));
		ptr2.y = cvRound(y0 - 1000 * a);

		line(dst, ptr1, ptr2, Scalar(0, 0, 255), 3, LINE_AA);
	}

	imshow("Dest", dst);
	waitKey(0);
	return 0;
}