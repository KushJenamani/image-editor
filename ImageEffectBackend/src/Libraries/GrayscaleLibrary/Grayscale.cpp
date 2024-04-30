#include "Grayscale.h"
#include<vector>
using namespace std;
void grayscale(vector<vector<Pixel>> &imageVector){
     int rows = imageVector.size();       // number of rows
    int columns = imageVector[0].size(); // number of columns
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            // old rgb values stored in R,G,B respectively
            int R = imageVector[i][j].r;
            int G = imageVector[i][j].g;
            int B = imageVector[i][j].b;
            //formula
            float grey=0.299*R+0.587*G+0.114*B;
            imageVector[i][j].r=grey;
            imageVector[i][j].g=grey;
            imageVector[i][j].b=grey;
        }
    }
}