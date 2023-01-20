#ifndef UTILS_H_
#define UTILS_H_

#include <iostream>
#include <vector>
#include <algorithm>
#include <opencv2/opencv.hpp>
#include "opencv2/imgproc.hpp"
using namespace std;
using namespace cv;

int moyEcart(vector<int>& liste);
int minimumX(vector<Rect>& rect);

/*
class SortFromHighestX {
public:
	bool operator()(Rect& r1, Rect& r2);
};
*/

#endif /* UTILS_H_ */