#include <opencv2/core/core.hpp> // Temel k�t�phane
#include <opencv2/highgui/highgui.hpp> // Giri� ��k�� i�lemlerinin bulundu�u k�t�phane
#include <iostream>

using namespace std;
using namespace cv;

Mat orgImg; // Resmi g�stermek i�in tan�mlanan matris

int main() {
	orgImg = imread("lena.jpg"); // Resmin okunma i�lemi
	namedWindow("Resim Penceresi", WINDOW_AUTOSIZE); // Resmin g�sterilece�i pencerenin tan�mlanmas�

	if(orgImg.empty()) { // Resmin y�klenememe durumu
		cout << "Resim yukleme hatasi." << endl;
		return -1;
	}
	else {
		imshow("Resim Penceresi", orgImg); // Resmin g�sterilmesi 
		waitKey(0); // Herhangi bir tu�a basana kadar resmin g�sterilmesine devam etsin
		destroyWindow("Resim Penceresi"); // Pencerenin kapat�lmas�
	}

	return 0;
}