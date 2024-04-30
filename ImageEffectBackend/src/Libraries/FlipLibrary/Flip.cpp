#include "Flip.h"
#include <vector>
using namespace std;
void flip(vector<vector<Pixel>> &imageVector, int horizontalFlipValue, int verticalFlipValue)
{
    int rows = imageVector.size();       // number of rows
    int columns = imageVector[0].size(); // number of columns
    if (horizontalFlipValue == 1)
    {
        for (int i = 0; i < columns / 2; i++)
        {
            for (int j = 0; j < rows; j++)
            {
                Pixel temp = imageVector[j][i];
                imageVector[j][i] = imageVector[j][columns - i - 1];
                imageVector[j][columns - 1 - i] = temp;
            }
        }
    }
    if (verticalFlipValue == 1)
    {
        for (int i = 0; i < rows / 2; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                Pixel temp = imageVector[i][j];
                imageVector[i][j] = imageVector[rows - 1 - i][j];
                imageVector[rows - 1 - i][j] = temp;
            }
        }
    }
}