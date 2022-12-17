#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0 ; i<height ; i++)
    {
        for (int j=0 ; j<width ; j++)
        {
            float color_red=image[i][j].rgbtRed;
            float color_green=image[i][j].rgbtGreen;
            float color_blue=image[i][j].rgbtBlue;

            int average= round((color_red + color_green + color_blue)/3);

            image[i][j].rgbtRed=average;
            image[i][j].rgbtBlue=average;
            image[i][j].rgbtGreen=average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0 ; i <height ; i++)
    {
        for (int j=0 ; j<width ; j++)
        {
            float original_red=image[i][j].rgbtRed;
            float original_green=image[i][j].rgbtGreen;
            float original_blue=image[i][j].rgbtBlue;

            int sepia_red=round(0.393*original_red+0.769*original_green+0.189*original_blue);
            int sepia_green=round((0.349*original_red)+(0.686*original_green)+(0.168*original_blue));
            int sepia_blue=round((0.272*original_red)+(0.534*original_green)+(0.131*original_blue));

            if (sepia_red > 255 )
            {
                sepia_red=255;
            }
            if (sepia_green > 255)
            {
                sepia_green=255;
            }
            if(sepia_blue>255)
            {
                sepia_blue=255;
            }
            image[i][j].rgbtRed=sepia_red;
            image[i][j].rgbtGreen=sepia_green;
            image[i][j].rgbtBlue=sepia_blue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i=0 ; i<height ; i++)
    {
        for (int j=0 ; j<width/2 ; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j]=image[i][width - (j+1)];
            image[i][width-(j+1)]=temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}


                     //THANKS TO CS50.......THIS TIME COUDLNT DO THE BLUR ONE :😔