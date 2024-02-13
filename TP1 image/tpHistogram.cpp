#include "tpHistogram.h"
#include <cmath>
#include <algorithm>
#include <tuple>
using namespace cv;
using namespace std;

/**
    Inverse a grayscale image with float values.
    for all pixel p: res(p) = 1.0 - image(p)
*/
Mat inverse(Mat image)
{
    // clone original image
    Mat res = image.clone();
    /********************************************
              YOUR CODE HERE
  *********************************************/
    cv::Size s = res.size();
    int rows = s.height;
    int cols = s.width;


    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            auto& pixel_RGB =  image.at<Vec3b>(Point(j, i));
            pixel_RGB[0] = 255 - pixel_RGB[0];
            pixel_RGB[1] = 255 - pixel_RGB[1];
            pixel_RGB[2] = 255 - pixel_RGB[2];

            res.at<Vec3b>(Point(j, i)) = pixel_RGB;

        }
    }
    /********************************************
                END OF YOUR CODE
    *********************************************/
    return res;
}

/**
    Thresholds a grayscale image with float values.
    for all pixel p: res(p) =
        | 0 if image(p) <= lowT
        | image(p) if lowT < image(p) <= hightT
        | 1 otherwise
*/
Mat threshold(Mat image, float lowT, float highT)
{
    Mat res = image.clone();
    assert(lowT <= highT);
    /********************************************
                YOUR CODE HERE
    *********************************************/
    int rows = res.rows;
    int cols = res.cols;


    /* OR
     cv::Size s = res.size();
    int rows = s.height;
    int cols = s.width;

    */
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {

            auto& pixel_RGB = image.at<Vec3b>(Point(j, i));
            if (pixel_RGB[0] <= lowT) {
                pixel_RGB[0] = 0;
                pixel_RGB[1] = 0;
                pixel_RGB[2] = 0;
            }
            else {
                if (pixel_RGB[0] > highT) {
                    pixel_RGB[0] = 255;
                    pixel_RGB[1] = 255;
                    pixel_RGB[2] = 255;
                }
            }
            res.at<Vec3b>(Point(j, i)) = pixel_RGB;
                
        }
            
    }
    /********************************************
                END OF YOUR CODE
    *********************************************/
    return res;
}

/**
    Quantize the input float image in [0,1] in numberOfLevels different gray levels.
    
    eg. for numberOfLevels = 3 the result should be for all pixel p: res(p) =
        | 0 if image(p) < 1/3
        | 1/2 if 1/3 <= image(p) < 2/3
        | 1 otherwise

        for numberOfLevels = 4 the result should be for all pixel p: res(p) =
        | 0 if image(p) < 1/4
        | 1/3 if 1/4 <= image(p) < 1/2
        | 2/3 if 1/2 <= image(p) < 3/4
        | 1 otherwise

        and so on for other values of numberOfLevels.

*/
Mat quantize(Mat image, int numberOfLevels)
{
    Mat res = image.clone();
    assert(numberOfLevels>0);
    /********************************************
                YOUR CODE HERE
    *********************************************/
    
    /********************************************
                END OF YOUR CODE
    *********************************************/
    return res;
}

/**
    Normalize a grayscale image with float values
    Target range is [minValue, maxValue].
*/
Mat normalize(Mat image, float minValue, float maxValue)
{
    Mat res = image.clone();
    assert(minValue <= maxValue);
    /********************************************
                YOUR CODE HERE
    *********************************************/
    
    /********************************************
                END OF YOUR CODE
    *********************************************/
    return res;
}



/**
    Equalize image histogram with unsigned char values ([0;255])

    Warning: this time, image values are unsigned chars but calculation will be done in float or double format.
    The final result must be rounded toward the nearest integer 
*/
Mat equalize(Mat image)
{
    Mat res = image.clone();
    /********************************************
                YOUR CODE HERE
    *********************************************/
    
    /********************************************
                END OF YOUR CODE
    *********************************************/
    return res;

}

/**
    Compute a binarization of the input float image using an automatic Otsu threshold.
    Input image is of type unsigned char ([0;255])
*/
Mat thresholdOtsu(Mat image)
{
    Mat res = image.clone();
    /********************************************
                YOUR CODE HERE
    *********************************************/
    
    /********************************************
                END OF YOUR CODE
    *********************************************/
    return res;
}
