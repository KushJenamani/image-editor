#include "GaussianBlur.h"
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

float weight (float distance, float radius) {
    static const float inv_sqrt_2pi = 0.3989422804014327;
    float a = (distance) / radius;

    return inv_sqrt_2pi / radius * std::exp(-0.5f * a * a);
}


void gauss_horizontal(vector<vector<Pixel>>* img, float radius) {
    if (radius == 0) return;
    
    int h = (*img).size();
    int v = (*img)[0].size();

    vector<vector<Pixel>>* newImg = new vector<vector<Pixel>>(h, vector<Pixel>(v));

    vector<float> weights(h);
    float weight_sum = 0;
    for (int i = 0; i < h; i++) {
        weights[i] = weight(i, radius);
        weight_sum += weights[i];
    }
    weight_sum /= (float)255;
    for (int i = 0; i < h; i++) {
        weights[i] / (weight_sum);
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < v; j++) {
            float r = 0, g = 0, b = 0;
            for (int k = 0; k < h; k++) {
                r += (*img)[k][j].r * weights[abs(k - i)];
                g += (*img)[k][j].g * weights[abs(k - i)];
                b += (*img)[k][j].b * weights[abs(k - i)];
            }
            (*newImg)[i][j].r = (int)r;
            (*newImg)[i][j].g = (int)g;
            (*newImg)[i][j].b = (int)b;

        }
    }

    *img = *newImg;
}


void gauss_vertical(vector<vector<Pixel>>* img, float radius) {
    if (radius <= 0.5) return;

    int h = (*img).size();
    int v = (*img)[0].size();

    vector<vector<Pixel>>* newImg = new vector<vector<Pixel>>(h, vector<Pixel>(v));

    vector<float> weights(v);
    float weight_sum = 0;
    for (int i = 0; i < v; i++) {
        weights[i] = weight(i, radius);
        weight_sum += weights[i];
    }
    weight_sum /= (float)255;
    for (int i = 0; i < v; i++) {
        weights[i] / (weight_sum + 1);
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < v; j++) {
            float r = 0, g = 0, b = 0;
            for (int k = 0; k < v; k++) {
                r += (*img)[i][k].r * weights[abs(k - j)];
                g += (*img)[i][k].g * weights[abs(k - j)];
                b += (*img)[i][k].b * weights[abs(k - j)];
            }
            (*newImg)[i][j].r = (int)r;
            (*newImg)[i][j].g = (int)g;
            (*newImg)[i][j].b = (int)b;

        }
    }

    *img = *newImg;
}


void gauss (vector<vector<Pixel>>* img, float radius) {
    gauss_horizontal(img, radius);
    gauss_vertical(img, radius);
}