#include "utils.h"
#include <stdio.h>

int moyEcart(vector<int>& liste){
	if (liste.size() > 1) {
		int ecart = 0;
		vector<int> newListe = liste;
		sort(newListe.begin(), newListe.end());
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

int minimumX(vector<Rect>& rect) {
	if (rect.size() > 0) {
		int minimum = rect[0].x;
		for (Rect r : rect) {
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
