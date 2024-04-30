#include "Brightness.h"
#include <vector>
using namespace std;
void brightness(vector<vector<Pixel>> &imageVector, float amount)
{
    int rows = imageVector.size();       // number of rows
    int columns = imageVector[0].size(); // number of columns
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            imageVector[i][j].r = (imageVector[i][j].r + amount) > 255 ? 255 : imageVector[i][j].r + amount;
            imageVector[i][j].g = (imageVector[i][j].g + amount) > 255 ? 255 : imageVector[i][j].g + amount;
            imageVector[i][j].b = (imageVector[i][j].b + amount) > 255 ? 255 : imageVector[i][j].b + amount;
        }
    }
}
