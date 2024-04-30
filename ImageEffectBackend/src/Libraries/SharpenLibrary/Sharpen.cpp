#include "Sharpen.h"
#include "../Pixel.h"
#include <vector>
using namespace std;

void sharpen(vector<vector<Pixel>>& img,float amount){
    vector<vector<int>> k = {{0,-1,0},{-1,4,-1},{0,-1,0}}; //convolution mat
    vector<vector<Pixel>> tmp(img);
    for (int i=1; i<img.size()-1; i++){ //iterating over the entire img, excluding borders
        for (int j=1; j<img[0].size()-1; j++){
            float R=0.0, G=0.0, B=0.0;
            for (int a=-1; a<2; a++){
                for (int b=-1; b<2; b++){
                    R += k[a+1][b+1] * img[a+i][b+j].r;
                    G += k[a+1][b+1] * img[a+i][b+j].g;
                    B += k[a+1][b+1] * img[a+i][b+j].b;
                }
            }
            tmp[i][j].r = max(0,min(255,(img[i][j].r + (int)(amount * R/16)))); 
            tmp[i][j].g = max(0,min(255,(img[i][j].g + (int)(amount * G/16))));
            tmp[i][j].b = max(0,min(255,(img[i][j].b + (int)(amount * B/16))));
        }
    }
    img = tmp;
}