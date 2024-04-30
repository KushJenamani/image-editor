#include "Invert.h"
#include <vector>
using namespace std;
void invert(vector<vector<Pixel>> &imageVector)
{
    int rows = imageVector.size();       // number of rows
    int columns = imageVector[0].size(); // number of columns
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            imageVector[i][j].r = 255 - imageVector[i][j].r;
            imageVector[i][j].g = 255 - imageVector[i][j].g;
            imageVector[i][j].b = 255 - imageVector[i][j].b;
        }
    }
}