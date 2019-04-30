#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat dst;
int sayac = 0;

int main() {
	Mat orgIm = imread("lena.jpg");
	
	while (true) {
		GaussianBlur(orgIm, dst, Size(sayac + 1, sayac + 1), 1); // 1 Standart sapma deðeridir.
		
		imshow("Org", orgIm);
		imshow("Dest", dst);

		waitKey(400);
		cout << sayac << endl;
		sayac+=2;
	}
	return 0;
}