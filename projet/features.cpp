#include "features.h"

cv::Point getCenterOfGravity(const cv::Mat& image) {
    cv::Moments moments = cv::moments(image);
    if (moments.m00 != 0) {
        double x = moments.m10 / moments.m00;
        double y = moments.m01 / moments.m00;
        return cv::Point(x, y);
    }
    else
        return cv::Point(-1, -1);
}


cv::Mat computeHarrisLaplacian(const cv::Mat& image) {
    cv::Mat harrisLaplacian;
    cornerHarris(image, harrisLaplacian, 3, 3, 0.04);
    return harrisLaplacian;
}


double density(cv::Mat& img) {
    int whitePixels = 0;
    int totalPixels = img.rows * img.cols;
    for (int i = 0; i < img.rows; i++) {
        for (int j = 0; j < img.cols; j++) {
            if (img.at<uchar>(i, j) == 255) {
                whitePixels++;
            }
        }
    }
    return (double)whitePixels / totalPixels;
}

std::vector<double> momentsHu(cv::Mat& img) {
    cv::Moments m = cv::moments(img, true);
    std::vector<double> hu;
    cv::HuMoments(m, hu);
    return hu;
}

std::vector<float> VandH_histograms(cv::Mat& img) {
    std::vector<float> histogrammes;
    int rows = img.rows;
    int cols = img.cols;
    cv::Mat vertical(rows, 1, CV_32FC1, cv::Scalar(0));
    cv::Mat horizontal(1, cols, CV_32FC1, cv::Scalar(0));

    // Boucle pour projeter horizontalement
    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; i++) {
            horizontal.at<float>(0, j) += img.at<uchar>(i, j);
        }
        histogrammes.push_back(horizontal.at<float>(0, j));
    }

    // Boucle pour projeter verticalement
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            vertical.at<float>(i, 0) += img.at<uchar>(i, j);
        }
        histogrammes.push_back(vertical.at<float>(i, 0));
    }

    // Normaliser les projections pour les afficher
    normalize(horizontal, horizontal, 0, 255, cv::NORM_MINMAX, CV_8UC1);
    normalize(vertical, vertical, 0, 255, cv::NORM_MINMAX, CV_8UC1);

    return histogrammes;
}

std::vector<float> HoG_descriptors(cv::Mat img) {
    std::vector<float> hog_descriptors;
    cv::HOGDescriptor hog;
    hog.winSize = cv::Size(256, 256); // Taille de la fenêtre de détection en pixels
    hog.blockSize = cv::Size(256, 256); // Taille du bloc
    hog.cellSize = cv::Size(128, 128); // Taille de la cellule
    hog.nbins = 9; // Nombre de bins
    hog.compute(img, hog_descriptors);
    return hog_descriptors;
}
