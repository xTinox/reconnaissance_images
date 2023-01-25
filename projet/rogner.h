#pragma once

#include <opencv2/opencv.hpp>
#include <vector>

using namespace cv;
using namespace std;

Mat rogner(Mat& img, int seuil);