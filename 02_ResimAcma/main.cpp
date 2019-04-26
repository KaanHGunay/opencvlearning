#include <opencv2/core/core.hpp> // Temel kütüphane
#include <opencv2/highgui/highgui.hpp> // Giriþ Çýkýþ iþlemlerinin bulunduðu kütüphane
#include <iostream>

using namespace std;
using namespace cv;

Mat orgImg; // Resmi göstermek için tanýmlanan matris

int main() {
	orgImg = imread("lena.jpg"); // Resmin okunma iþlemi
	namedWindow("Resim Penceresi", WINDOW_AUTOSIZE); // Resmin gösterileceði pencerenin tanýmlanmasý

	if(orgImg.empty()) { // Resmin yüklenememe durumu
		cout << "Resim yukleme hatasi." << endl;
		return -1;
	}
	else {
		imshow("Resim Penceresi", orgImg); // Resmin gösterilmesi 
		waitKey(0); // Herhangi bir tuþa basana kadar resmin gösterilmesine devam etsin
		destroyWindow("Resim Penceresi"); // Pencerenin kapatýlmasý
	}

	return 0;
}