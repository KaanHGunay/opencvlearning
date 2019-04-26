#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
	VideoCapture vid("patron.mp4"); // Video dosyas�na ula�ma
	namedWindow("Video", WINDOW_AUTOSIZE); // Videonun g�sterilece�i pencere
	float fps = vid.get(CAP_PROP_FPS); // Video fps de�erine ula�ma
	cout << fps << endl;
	/*
	if (vid.isOpened()) {
		cout << "Videoya ulasilamamaktad�r." << endl;
		return -1;
	}*/

	while (true) { // Videonun t�m framelerini matrise atmak i�in sonsuz d�ng� olu�turuyoruz.
		Mat video;
		bool frame = vid.read(video); // Matrise atma i�lemi

		if (waitKey(30) == 27 || frame == 0) { // ESC tu�una bas�ld�ysa veya t�m frameler okunduysa
			destroyWindow("Video");
			break;
		}

		imshow("Video", video);
	}

	return 0;
}