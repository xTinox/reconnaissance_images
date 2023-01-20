#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/features2d.hpp>
#include <string>
#include <filesystem>

using namespace std;
using namespace cv;
namespace fs = filesystem;

int main()
{
    for (int i = 1; i < 6; i++) {
        // Charger l'image
        Mat img = imread("exemples/casualty_000_10_5_" + to_string(i) + ".png");

        // Créer un objet SIFT
        Ptr<SIFT> sift = SIFT::create(50);

        // Détecter et extraire les caractéristiques de l'image
        vector<KeyPoint> keypoints;
        Mat descriptors;
        sift->detectAndCompute(img, noArray(), keypoints, descriptors);

        // Afficher les caractéristiques extraites sur l'image
        Mat img_keypoints;
        drawKeypoints(img, keypoints, img_keypoints);
        imshow("Image", img_keypoints);
        waitKey();
    }

    /*

    double density = countNonZero(img) / (double)(img.rows * img.cols);

    Moments moments(img, true);
    Point2f center(moments.m10 / moments.m00, moments.m01 / moments.m00);



    vector<vector<Point> > contours;
    vector<Vec4i> hierarchy;

    findContours(img, contours, hierarchy, RETR_CCOMP, CHAIN_APPROX_SIMPLE);

    Rect bounding_rect;
    for (int i = 0; i < contours.size(); i++)
        bounding_rect = bounding_rect + boundingRect(contours[i]);

    int width = bounding_rect.width;
    int height = bounding_rect.height;
    */

    return 0;
}


/*
    const string cheminImg = "exemples/";

    //Boucle sur toutes les pages de tous les scripters
    for (int i = 1; i < 7; i++) {
        for (int j = 1; j < 3; j++) {
            cout << "Scripter: " << i  << " Page: " << j << endl;

            // Train
            
            stringstream buff;
            buff << setfill('0') << setw(5) << i * 100 + j;
            String str = "../all-scans/" + buff.str() + ".png";
            
            

            // Appel de la fonction de détection de contours + enregistrement des fichiers .png + .txt
            cout << str << endl;
            }
        }
    waitKey();
    return 0;
}
*/