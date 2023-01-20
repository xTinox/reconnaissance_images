#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>
#include <filesystem>

using namespace std;
using namespace cv;
namespace fs = filesystem;

int main()
{
    // Création des 3 répertoires
    // 'exemples/' : imagettes manuscrites
    // 'exemples_modeles/' : imagettes modèles
    // 'exemples_txt/' : fichier texte de chaque imagette manuscrite
    const string cheminImg = "test/";
    const string cheminModele = "test_modeles/";
    const string cheminTxt = "test_txt/";

    // Chemin du dossier de donnees
    const string donnees = "../donnees/";

    fs::create_directories(cheminImg);
    fs::create_directories(cheminModele);
    fs::create_directories(cheminTxt);

    //Boucle sur toutes les pages de tous les scripters
    for (int i = 1; i < 7; i++) {
        for (int j = 1; j < 3; j++) {
            cout << "Scripter: " << i  << " Page: " << j << endl;

            // Train
            /*
            stringstream buff;
            buff << setfill('0') << setw(5) << i * 100 + j;
            String str = "../all-scans/" + buff.str() + ".png";
            */

            // Test
            
            stringstream buff1;
            buff1 << setfill('0') << setw(2) << i;
            stringstream buff2;
            buff2 << setfill('0') << setw(4) << j;
            String str = donnees + "s" + buff1.str() + "_" + buff2.str() + ".png";
            

            // Appel de la fonction de détection de contours + enregistrement des fichiers .png + .txt
            cout << str << endl;
            }
        }
    waitKey();
    return 0;
}