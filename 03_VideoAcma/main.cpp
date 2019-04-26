#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
	VideoCapture vid("patron.mp4"); // Video dosyasýna ulaþma
	namedWindow("Video", WINDOW_AUTOSIZE); // Videonun gösterileceði pencere
	float fps = vid.get(CAP_PROP_FPS); // Video fps deðerine ulaþma
	cout << fps << endl;
	/*
	if (vid.isOpened()) {
		cout << "Videoya ulasilamamaktadýr." << endl;
		return -1;
	}*/

	while (true) { // Videonun tüm framelerini matrise atmak için sonsuz döngü oluþturuyoruz.
		Mat video;
		bool frame = vid.read(video); // Matrise atma iþlemi

		if (waitKey(30) == 27 || frame == 0) { // ESC tuþuna basýldýysa veya tüm frameler okunduysa
			destroyWindow("Video");
			break;
		}

		imshow("Video", video);
	}

	return 0;
}