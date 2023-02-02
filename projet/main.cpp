#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/features2d.hpp>
#include <string>
#include <filesystem>
#include "utils.h"
#include "features.h"

using namespace std;
using namespace cv;
namespace fs = filesystem;

int main()
{
    //vector<string>images;
    //images.push_back("exemples/injury_021_15_1_1.png");
    //images.push_back("exemples/accident_000_00_1_1.png");
    generateARFF("ex", "hog_small_base.arff");
    /*
    for (string imag : images){
    //for (int i = 1; i < 6; i++) {
        //Mat img = imread("exemples/injury_021_15_1_" + to_string(i) + ".png", IMREAD_GRAYSCALE);
        Mat img = imread(imag, IMREAD_GRAYSCALE);
        //resize(img, img, Size(), 2, 2, INTER_LINEAR);
        img = rogner(img, 250);
        
        // Créer un objet SIFT

        Ptr<SIFT> sift = SIFT::create();
        //Ptr<SiftFeatureDetector> sift = SiftFeatureDetector::create(50);

        // Détecter et extraire les caractéristiques de l'image
        vector<KeyPoint> keypoints;
        Mat descriptors;
        sift->detectAndCompute(img, noArray(), keypoints, descriptors);
        //std::cout << keypoints.size() << std::endl;

        

        // Afficher les caractéristiques extraites sur l'image
        Mat img_keypoints;
        drawKeypoints(img, keypoints, img_keypoints, Scalar::all(-1), DrawMatchesFlags::DRAW_RICH_KEYPOINTS);

        
        Ptr<SiftDescriptorExtractor> descriptor = SiftDescriptorExtractor::create();
        Mat descripteurs;
        descriptor->compute(img, keypoints, descripteurs);

        Mat descript_keypoints;
        drawKeypoints(img, keypoints, descript_keypoints, Scalar::all(1), DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
        imshow("Description", descript_keypoints);
        


        imshow("Image", img_keypoints);
        imshow("Descriptor", descriptors);
        cout << descriptors.size() << endl;
        cout << descripteurs.size() << endl;
        
        waitKey(0);
        
    
    }*/

    
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