#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>

using namespace std;
using namespace cv;

// Trackbar fpnksiyon parametrelerini gerçek zamanlý olarak deðiþtirmeye yarar.
int trackVal;
// Trackbara göre deðiþecek fonksiyonun tanýmlanmasý
void callbackTrack(int, void*) {
	cout << trackVal << endl;
}

int main() {
	namedWindow("Trackbar", WINDOW_AUTOSIZE);
	// tb -> trackbarýn adý
	// Trackbat -> bulunacaðý pencerenin adý
	// trackVal -> trackbarýn deðeri
	// 100 -> Trackbar için maksimum deðer
	// callbackTrack -> Trackbar deðiþtiðinde çaðýralacak fonksiyon
	createTrackbar("tb", "Trackbar", &trackVal, 100, callbackTrack);

	/*while (true) {
		if (waitKey(30) == 27) break; // ESC ye basýlýrsa çýk
	}*/

	waitKey(0);
	return 0;
}
