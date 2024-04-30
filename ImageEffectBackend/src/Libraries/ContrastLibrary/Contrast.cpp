#include "Contrast.h"
#include <vector>
using namespace std;

void contrast (vector<vector<Pixel>>* imageVector, float amount) {
	for (int i = 0; i < imageVector -> size(); i++) {
		for (Pixel& pixel : (*imageVector)[i]) {
			pixel.r = min(255, (int)(pixel.r * (amount / 100)));
			pixel.g = min(255, (int)(pixel.g * (amount / 100)));
			pixel.b = min(255, (int)(pixel.b * (amount / 100)));
		}
	}

}