#include <stdio.h>
#include <algorithm>
#include <string>
#include <iostream>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

int main(int argc,char **argv)
{
    cv::Mat img1 = imread("Test_Pic.jpg",cv::ImreadModes::IMREAD_COLOR);
    cv::Mat img2 = imread("Test_Pic.jpg",cv::ImreadModes::IMREAD_REDUCED_GRAYSCALE_2);

    cout << img1.size() << endl;
    cout << img2.size() << endl;
    cv::imshow("Test_Pic_COLOR",img1);
    cv::imshow("Test_Pic_GRAY2",img2);

    cv::imwrite("Test_Pic_COLOR.jpg",img1);
    cv::imwrite("Test_Pic_GRAY2.jpg",img2);

    waitKey(0);
    
    return 0;
}
