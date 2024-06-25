#include <stdio.h>
#include "opencv2/opencv.hpp"

using namespace cv;

int main(int argc,char **argv)
{
    Mat image;
    image = imread("Test_Pic.jpg");
    namedWindow("Display Image");
    resize(image,image,Size_<double>(680,480));
    imshow("Display Image",image);
    waitKey(0);
    return 0;
}
