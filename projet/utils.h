#pragma once

#include <opencv2/opencv.hpp>
#include <vector>
#include <Windows.h>
#include <algorithm>
#include "opencv2/imgproc.hpp"
#include <filesystem>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


int moyEcart(std::vector<int>& liste);
int minimumX(std::vector<cv::Rect>& rect);
cv::Mat normaliser(cv::Mat& desc, int n);
cv::Mat completer_de_0(cv::Mat& desc, int n);
cv::Mat rogner(cv::Mat& img, int seuil);
void generateARFF(const std::string& folderPath, const std::string& outputFile);
std::vector<cv::Mat> zoning(cv::Mat& img, int nbRow, int nbCol);