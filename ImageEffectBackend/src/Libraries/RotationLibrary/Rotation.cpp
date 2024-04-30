#include "Rotation.h"
#include <vector>
#include <iostream>
using namespace std;

void rotateBy180(vector<vector<Pixel>>* img){

    int m=(*img).size();
    int n=(*img)[0].size();

    
    int order = m;
    if (n > m)  order = n;

    if (m == n){
        //Form a new matrix and colour it using values of the old matrix (Trying to colour the original matrix directly leads to wrong answers)
        vector<vector<Pixel>> tempGrid(m, vector<Pixel>(m));
        for (int i = 0; i < m; i++){
            for (int j = 0; j < m; j++){
                tempGrid[i][j].r = (*img)[i][j].r;      tempGrid[i][j].g = (*img)[i][j].g;      tempGrid[i][j].b = (*img)[i][j].b;
            }
        }
        for(int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                (*img)[m-1-i][n-1-j].r = tempGrid[i][j].r;
                (*img)[m-1-i][n-1-j].g = tempGrid[i][j].g;
                (*img)[m-1-i][n-1-j].b = tempGrid[i][j].b;
            }
        }
    }
    else{
        vector<vector<Pixel>> newGrid(order, vector<Pixel>(order));
        for (int i = 0; i < order; i++){
            for (int j = 0; j < order; j++){
                if ((0 <= i && i <= m-1) && (0 <= j && j <= n-1)){
                    newGrid[i][j].r = (*img)[i][j].r;      newGrid[i][j].g = (*img)[i][j].g;      newGrid[i][j].b = (*img)[i][j].b;
                }
                else{
                    newGrid[i][j].r = newGrid[i][j].g = newGrid[i][j].b = 0;
                }
            }
        }

        for (int i = 0; i < order; i++){
            for (int j = 0; j < order; j++){
                if ((0 <= (order-1-i) && (order-1-i) <= m) && (0 <= (order-1-j) && (order-1-j) <= n)){
                    (*img)[order-1-i][order-j].r = newGrid[i][j].r;
                    (*img)[order-1-i][order-j].g = newGrid[i][j].g;
                    (*img)[order-1-i][order-j].b = newGrid[i][j].b;
                }
            }
        }

    }
}

void rotateBy90(vector<vector<Pixel>>* img){
    
    int m=(*img).size();
    int n=(*img)[0].size();

    if (m == n && false){
        vector<vector<Pixel>> tempGrid(m, vector<Pixel>(m));
        for (int i = 0; i < m; i++){
            for (int j = 0; j < m; j++){
                tempGrid[i][j].r = (*img)[i][j].r;      tempGrid[i][j].g = (*img)[i][j].g;      tempGrid[i][j].b = (*img)[i][j].b;
            }
        }
        for (int i = 0; i < m; i++){
            for (int j = 0; j < m; j++) {
                (*img)[i][j].r = tempGrid[j][m-i-1].r;
                (*img)[i][j].g = tempGrid[j][m-i-1].g;
                (*img)[i][j].b = tempGrid[j][m-i-1].b;
            }
        }      
    }
    else{
        // vector<vector<Pixel>> newGrid(order, vector<Pixel>(order));
        // for (int i = 0; i < order; i++){
        //     for (int j = 0; j < order; j++){
        //         if ((0 <= i && i <= m-1) && (0 <= j && j <= n-1)){
        //             newGrid[i][j].r = (*img)[i][j].r;      newGrid[i][j].g = (*img)[i][j].g;      newGrid[i][j].b = (*img)[i][j].b;
        //         }
        //         else{
        //             newGrid[i][j].r = newGrid[i][j].g = newGrid[i][j].b = 0;
        //         }
        //     }
        // }

        // for (int i = 0; i < order; i++){
        //     for (int j = 0; j < order; j++){
        //         if ((0 <= (order-1-i) && (order-1-i) <= m) && (0 <= (order-1-j) && (order-1-j) <= n)){
        //             (*img)[order-1-j][i].r = newGrid[i][j].r;
        //             (*img)[order-1-j][i].g = newGrid[i][j].g;
        //             (*img)[order-1-j][i].b = newGrid[i][j].b;
        //         }
        //     }
        // }

        vector<vector<Pixel>>* newImage = new vector<vector<Pixel>>(n, vector<Pixel>(m));

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++) {
                (*newImage)[j][m-i-1].r = (*img)[i][j].r;
                (*newImage)[j][m-i-1].g = (*img)[i][j].g;
                (*newImage)[j][m-i-1].b = (*img)[i][j].b;
            }
        } 

        *img = *newImage;
    }
}

void rotation(vector<vector<Pixel>>* img, int value){
    int angle = value;
    printf("ROTATION ANGLE: %d\n", value);
    if (angle == 2)   {
        rotateBy90(img);
        rotateBy90(img);
    }
    else if (angle == 1)   rotateBy90(img);
    else if (angle == 3){
        rotateBy90(img);
        rotateBy90(img);
        rotateBy90(img);
    }
}