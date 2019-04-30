#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
	Mat orgIm = imread("lena.jpg");
	cvtColor(orgIm, orgIm, COLOR_BGR2GRAY);
	// 100 - 150 -> Piksel deðerlerinin türevi alýnýrkenken kenarý elde etmek için kullanýlan türev iþleminin eþik aralýðýný belirtir.
	Canny(orgIm, orgIm, 100, 150); 
	imshow("Image", orgIm);

	waitKey(0);
	return 0;
}