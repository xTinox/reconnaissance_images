#include "rogner.h"

Mat rogner(Mat& img, int seuil) {

    resize(img, img, Size(), 2, 2, INTER_LINEAR);
    threshold(img, img, 120, 255, THRESH_BINARY);

    vector<vector<Point>> contours;
    findContours(img, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
    
    Scalar color(0, 0, 0);

    int max_area = 0;
    int max_index = 0;
    for (int i = 0; i < contours.size(); i++) {
        drawContours(img, contours, i, color, 1);
        double area = contourArea(contours[i]);
        if (area > max_area and area < (img.size[0]*100)) {
            max_area = area;
            max_index = i;
        }
    }

    //Mat img_contour = Mat::zeros(img.size(), CV_8UC3);
    
    

    //Rect rect = boundingRect(contours[0]);
    //;
    //Mat cropped = img_contour(rect);
    cout << contours.size() << endl;
    imshow("crop", img);
    return img;
}