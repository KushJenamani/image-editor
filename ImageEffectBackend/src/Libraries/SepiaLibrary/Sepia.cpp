#include "Sepia.h"
#include <vector>
using namespace std;
void sepia(vector<vector<Pixel>> &imageVector)
{
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
            // updating rgb values according to sepia formula
            // if value's is greater than 255, cap it at 255
            imageVector[i][j].r = (R * 0.393 + G * 0.769 + B * 0.189) >= 255 ? 255 : (int)(R * 0.393 + G * 0.769 + B * 0.189);
            imageVector[i][j].g = (R * 0.349 + G * 0.686 + B * 0.168) >= 255 ? 255 : (int)(R * 0.349 + G * 0.686 + B * 0.168);
            imageVector[i][j].b = (R * 0.272 + G * 0.534 + B * 0.131) >= 255 ? 255 : (int)(R * 0.272 + G * 0.534 + B * 0.131);
        }
    }
}