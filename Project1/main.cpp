#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	Mat crtImg(240, 240, CV_8UC3, Scalar(200, 200, 200));

	namedWindow("Resim Penceresi", WINDOW_AUTOSIZE);
	imshow("Resim Penceresi", crtImg);
	waitKey(0);
	destroyWindow("Resim Penceresi");

	return 0;
}

/*
	Yapılandırkma > VC++ Dizinleri
	Ekleme kodu dizini; C:\opencv\build\include
	Kitaplık Dizinleri; C:\opencv\build\x64\vc14\lib

	Bağlayıcı > Giriş
	Ek Bağımlılıklar; opencv_world410d.lib
*/