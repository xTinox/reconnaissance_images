#include "utils.h"
#include "features.h"

int moyEcart(std::vector<int>& liste) {
    if (liste.size() > 1) {
        int ecart = 0;
        std::vector<int> newListe = liste;
        std::sort(newListe.begin(), newListe.end());
        for (int i = 1; i < newListe.size(); i++) {
            ecart += newListe[i] - newListe[i - 1];
            //cout << ecart << "     " << newListe.size() << endl;
        }
        ecart = ecart / 5 + 160; //3.5
        return ecart;
    }
    else if (liste.size() == 1) {
        return liste[0];
    }
    else {
        return 0;
    }


}

int minimumX(std::vector<cv::Rect>& rect) {
    if (rect.size() > 0) {
        int minimum = rect[0].x;
        for (cv::Rect r : rect) {
            if (minimum > r.x) {
                minimum = r.x;
            }
        }
        return minimum;
    }
    else {
        return 0;
    }
}

void generateARFF(const std::string& folderPath, const std::string& outputFile) {
    /*
    filesystem::path fPath(folderPath);
    if (!filesystem::exists(fPath) || !filesystem::is_directory(fPath)) {
        //filesystem::create_directories(folderPath);
        cout << "pas bon !" << endl;
        return;
    }
    */
    //string const filePath(folderPath + outputFile);
    std::ofstream out(outputFile.c_str());
    out << "@relation image_classification" << std::endl;
    /*
    out << "@attribute density numeric" << std::endl;
    out << "@attribute x_center numeric" << std::endl;
    out << "@attribute y_center numeric" << std::endl;
    out << "@attribute class {accident,bomb,car,casualty,electricity,fire,firebrigade,flood,gas,injury,paramedics,person,police,roadblock}" << std::endl;
    */
    /*
    int R = 4;
    int C = 4;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            for (int k = 0; k < 7; k++) {
                out << "@attribute huMoments_" << i << "_" << j << "_" << k+1 << " real" << std::endl;
            }
        }
    }
    */
    /*
    for (int i = 0; i < 256*2; i++) {
        out << "@attribute VnHhisto_" << i << " real" << std::endl;
    }
    */

    
    for (int i = 0; i < 36; i++) {
        out << "@attribute hog_" << i << " real" << std::endl;
    }
    out << "@attribute class {accident,bomb,car,casualty,electricity,fire,firebrigade,flood,gas,injury,paramedics,person,police,roadblock}" << std::endl;
    //out << "@attribute class {accident,bomb,car,casualty,injury}" << std::endl;
    out << "@data" << std::endl;
    
    HANDLE hFind;
    WIN32_FIND_DATA data;
    int compteur = 0;
    if ((hFind = FindFirstFile((folderPath + "/*.png").c_str(), &data)) != INVALID_HANDLE_VALUE) {
        do {
            std::string fileName = data.cFileName;
            std::cout << fileName << std::endl;

            std::string className = fileName.substr(0, fileName.find("_"));
            cv::Mat img = cv::imread(folderPath + "/" + fileName, cv::IMREAD_GRAYSCALE);
            //resize(img, img, cv::Size(), 2, 2, cv::INTER_LINEAR);
            img = rogner(img, 230);
            /*
            std::vector<cv::Mat> zones = zoning(img,R,C);

            for (cv::Mat m : zones) {
                std::vector<double> hu;
                hu = momentsHu(m);
                for (double h : hu) {
                    out << h << ",";
                }
            }
            */

            /* Refaire pour OUPTPUTFILE7
            std::vector<float> histos;
            histos = VandH_histograms(img);
            
            for (int i = 0; i < 256*2; i++) {
                out << histos[i] << ",";
            }
            */

            std::vector<float> hog_desc;
            hog_desc = HoG_descriptors(img);
            //std::cout << hog_desc.size() << std::endl;
            
            for (float i : hog_desc) {
                out << i << ",";
            }
            
            out << className << std::endl;
            
            /***
            cv::Ptr<cv::SIFT> sift = cv::SIFT::create(10);
            std::vector<cv::KeyPoint> keypoints;
            cv::Mat descriptors;
            sift->detectAndCompute(img, cv::noArray(), keypoints, descriptors);
            ***/
            /*
            std::sort(keypoints.begin(), keypoints.end(),
                [](const cv::KeyPoint& kp1, const cv::KeyPoint& kp2) {
                    return kp1.response > kp2.response;
                });

            int N = 10;
            keypoints.resize(N);

            // Réduire les descripteurs pour correspondre aux N points clés conservés
            descriptors = descriptors.rowRange(0, N);

            for (int i = 0; i < descriptors.rows; i++)
            {
                for (int j = 0; j < descriptors.cols; j++)
                {
                    out << descriptors.at<float>(i, j);
                    if (j < descriptors.cols - 1)
                    {
                        out << ",";
                    }
                }
            }
            out << "," << className << std::endl;
            std::cout << keypoints.size() << std::endl;
            //cv::Point center = getCenterOfGravity(img);
            //double densityValue = density(img);
            //out << densityValue << "," << center.x << "," << center.y << "," << className << std::endl;
            compteur++;
            */
            /****
            cv::Mat meanDescriptor = cv::Mat::zeros(1, descriptors.cols, descriptors.type());
            for (int i = 0; i < descriptors.rows; i++) {
                meanDescriptor += descriptors.row(i);
            }
            meanDescriptor /= descriptors.rows;

            
            for (int i = 0; i < meanDescriptor.cols; i++) {
                if (meanDescriptor.at<float>(0, i) > descriptors.rows/2) {
                    out << 1 << ",";
                }
                else {
                    out << 0 << ",";
                }
            }
            ****/
            /******
            descriptors = completer_de_0(descriptors,N);
            std::cout << descriptors.rows << std::endl;
            for (int i = 0; i < descriptors.rows; i++)
            {
                for (int j = 0; j < descriptors.cols; j++)
                {
                    out << descriptors.at<float>(i, j) << ",";
                }
            }
            out << "," << className << std::endl;
            *****/

            //std::cout << meanDescriptor.size() << std::endl;
            //std::cout << meanDescriptor << std::endl;
            //std::cout << descriptors.size() << std::endl;
            //resize(meanDescriptor, meanDescriptor, cv::Size(), 16, 16, cv::INTER_LINEAR);
            //cv::Mat img_keypoints;
            //drawKeypoints(img, keypoints, img_keypoints, cv::Scalar::all(-1), cv::DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
            //imshow("Description", img_keypoints);
            //imshow("Descriptor", descriptors);
            //cv::waitKey(0);
            

        } while (FindNextFile(hFind, &data) and compteur < 10000);
        FindClose(hFind);
    }
}


cv::Mat normaliser(cv::Mat& desc, int n) {
    cv::Mat normal;
    cv::resize(desc, normal, cv::Size(desc.cols,n));
    return normal;
}

cv::Mat completer_de_0(cv::Mat& desc, int N) {
    cv::Mat completer;
    int top = 0;
    int bottom = N - desc.rows;
    cv::copyMakeBorder(desc, completer, top, bottom, 0, 0, 0);
    return completer;
}


cv::Mat rogner(cv::Mat& img, int seuil) {

    //resize(img, img, Size(), 2, 2, INTER_LINEAR);
    threshold(img, img, seuil, 255, cv::THRESH_BINARY);

    std::vector<cv::Vec4i> hierarchy;
    std::vector<std::vector<cv::Point>> contours;
    findContours(img, contours, hierarchy , cv::RETR_CCOMP, cv::CHAIN_APPROX_SIMPLE);

    //Scalar color(0, 0, 0);

    int max_area = 0;
    int max_index = 0;
    for (int i = 0; i < contours.size(); i++) {
        //drawContours(img, contours, i, color, 1);
        double area = contourArea(contours[i]);
        if (area > max_area and area < 0.9*(img.size[0]*img.size[1])) {
            max_area = area;
            max_index = i;
        }
    }

    cv::Mat img_contour = cv::Mat::zeros(img.size(), CV_8UC3);
    cv::Rect rect = boundingRect(contours[max_index]);

    cv::Mat cropped = img(rect);

    resize(cropped, cropped, cv::Size(256, 256)); // Resize en carré de 256x256 pixels

    //imshow("crop", cropped);
    //waitKey(0);
    return cropped;
}

std::vector<cv::Mat> zoning(cv::Mat& img, int nbRow, int nbCol) {
    std::vector<cv::Mat> zones;
    int rows = img.rows;
    int cols = img.cols;
    int regionRows = rows / nbRow;
    int regionCols = cols / nbCol;

    for (int i = 0; i < nbRow; i++) {
        for (int j = 0; j < nbCol; j++) {
            cv::Rect region(j * regionCols, i * regionRows, regionCols, regionRows);
            cv::Mat roi = img(region);
            zones.push_back(roi);
        }
    }
    return zones;
}