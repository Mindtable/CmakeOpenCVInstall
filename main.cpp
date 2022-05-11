#include "iostream"
#include <opencv2/highgui.hpp>
//#include "opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main() {
    Mat img = imread("../Baby_fish.jpeg");
    if (img.empty()) {
        cout << "Error" << endl;
        return -1;
    }
    imshow("Lena", img);
    waitKey();
    return 0;
}