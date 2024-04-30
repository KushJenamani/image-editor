#ifndef GAUSSIAN_BLUR_H
#define GAUSSIAN_BLUR_H
#include "../Pixel.h"
#include <vector>
using namespace std;

void gauss(vector<vector<Pixel>>* img, float radius);

#endif