#ifndef FEATURES_H_
#define FEATURES_H_

#include <iostream>
#include <vector>
#include <algorithm>
#include <opencv2/opencv.hpp>
#include <opencv2/objdetect.hpp>
#include "opencv2/imgproc.hpp"
#include <opencv2/features2d.hpp>
#include <filesystem>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>

cv::Point getCenterOfGravity(const cv::Mat& image);
cv::Mat computeHarrisLaplacian(const cv::Mat& image);
double density(cv::Mat& img);
std::vector<double> momentsHu(cv::Mat& img);
std::vector<float> VandH_histograms(cv::Mat& img);
std::vector<float> HoG_descriptors(cv::Mat img);


/*
class SortFromHighestX {
public:
	bool operator()(Rect& r1, Rect& r2);
};
*/

#endif /* FEATURES_H_ */