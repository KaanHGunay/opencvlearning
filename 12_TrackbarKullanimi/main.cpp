#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>

using namespace std;
using namespace cv;

// Trackbar fpnksiyon parametrelerini ger�ek zamanl� olarak de�i�tirmeye yarar.
int trackVal;
// Trackbara g�re de�i�ecek fonksiyonun tan�mlanmas�
void callbackTrack(int, void*) {
	cout << trackVal << endl;
}

int main() {
	namedWindow("Trackbar", WINDOW_AUTOSIZE);
	// tb -> trackbar�n ad�
	// Trackbat -> bulunaca�� pencerenin ad�
	// trackVal -> trackbar�n de�eri
	// 100 -> Trackbar i�in maksimum de�er
	// callbackTrack -> Trackbar de�i�ti�inde �a��ralacak fonksiyon
	createTrackbar("tb", "Trackbar", &trackVal, 100, callbackTrack);

	/*while (true) {
		if (waitKey(30) == 27) break; // ESC ye bas�l�rsa ��k
	}*/

	waitKey(0);
	return 0;
}
