#include "HueSaturation.h"
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
void hueSaturation(vector<vector<Pixel>>& image, int hue, int saturation) {
    int hueRadians = hue * M_PI / 180.0f;
    int saturationFactor = saturation / 100.0f;
    int cosHue = cos(hueRadians);
    int sinHue = sin(hueRadians);
    int oneMinusCosHue = 1.0f - cosHue;
    int oneThird = 1.0f / 3.0f;
    int oneMinusSaturationFactor = 1.0f - saturationFactor;
    int redFactor = oneThird * oneMinusSaturationFactor;
    int greenFactor = oneThird * oneMinusSaturationFactor;
    int blueFactor = oneThird * oneMinusSaturationFactor;
    int redFactorTimesOneMinusCosHue = redFactor * oneMinusCosHue;
    int redFactorTimesSinHue = redFactor * sinHue;
    int greenFactorTimesOneMinusCosHue = greenFactor * oneMinusCosHue;
    int greenFactorTimesSinHue = greenFactor * sinHue;
    int blueFactorTimesOneMinusCosHue = blueFactor * oneMinusCosHue;
    int blueFactorTimesSinHue = blueFactor * sinHue;
    for (auto& row : image) {
        for (auto& pixel : row) {
            int red = pixel.r / 255.0f;
            int green = pixel.g / 255.0f;
            int blue = pixel.b / 255.0f;
            int luminance = red * 0.2126f + green * 0.7152f + blue * 0.0722f;
            int redPrime = red * oneMinusSaturationFactor + luminance * redFactorTimesOneMinusCosHue + luminance * redFactorTimesSinHue;
            int greenPrime = green * oneMinusSaturationFactor + luminance * greenFactorTimesOneMinusCosHue + luminance * greenFactorTimesSinHue;
            int bluePrime = blue * oneMinusSaturationFactor + luminance * blueFactorTimesOneMinusCosHue + luminance * blueFactorTimesSinHue;
            pixel.r = static_cast<int>(redPrime * 255.0f);
            pixel.g = static_cast<int>(greenPrime * 255.0f);
            pixel.b = static_cast<int>(bluePrime * 255.0f);

            pixel.r = min(255, max(0, pixel.r));    //clamp the values to be between 0 and 255
            pixel.g = min(255, max(0, pixel.g));
            pixel.b = min(255, max(0, pixel.b));
        }
    }
}