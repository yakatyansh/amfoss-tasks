#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i=0; i< height; i++)
    {
        for(int j=0;  j<width;  j++)
        {
            float Red = image[i][j].rgbtRed;
            float Green = image[i][j].rgbtGreen;
            float Blue = image[i][j].rgbtBlue;
            
            int average=round((Red+Green+Blue)/3);
            image[i][j].rgbtRed=image[i][j].rgbtGreen=image[i][j].rgbtBlue=average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i=0; i<height; i++)
    {
        for (int j=0;j<width;j++)
        {
            float oRed = image[i][j].rgbtRed;
            float oGreen = image[i][j].rgbtGreen;
            float oBlue = image[i][j].rgbtBlue;
            
            int sRed = round(0.393*oRed + 0.769*oGreen + 0.189*oBlue);
            int sGreen = round(0.349*oRed + 0.686*oGreen + 0.168*oBlue);
            int sBlue = round(0.272*oRed + 0.534*oGreen + 0.131*oBlue);
            
            if (sRed>256)
            {
                sRed=255;
            }
            
            if (sBlue>=256)
            {
                sBlue=255;
            }
            
            if (sGreen>=256)
            {
                sGreen=255;
            }
            
            image[i][j].rgbtRed=sRed;
            image[i][j].rgbtGreen=sGreen;
            image[i][j].rgbtBlue=sBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i<height; i++)
    {
        for(int j=0; j<width/2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - (j+1)];
            image[i][width - (j+1)]=temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    for (int i = 0, red, green, blue, count; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            red = green = blue = count = 0;

            if (i >= 0 && j >= 0)
            {
                red += tmp[i][j].rgbtRed;
                green += tmp[i][j].rgbtGreen;
                blue += tmp[i][j].rgbtBlue;
                count++;
            }

            if (i >= 0 && j - 1 >= 0)
            {
                red += temp[i][j-1].rgbtRed;
                green += temp[i][j-1].rgbtGreen;
                blue += temp[i][j-1].rgbtBlue;
                count++;
            }

            if ((i >= 0 && j + 1 >= 0) && (i >= 0 && j + 1 < width))
            {
                red += temp[i][j+1].rgbtRed;
                green += temp[i][j+1].rgbtGreen;
                blue += temp[i][j+1].rgbtBlue;
                count++;
            }

            if (i - 1 >= 0 && j >= 0)
            {
                red += temp[i-1][j].rgbtRed;
                green += temp[i-1][j].rgbtGreen;
                blue += temp[i-1][j].rgbtBlue;
                count++;
            }

            if (i - 1 >= 0 && j - 1 >= 0)
            {
                red += temp[i-1][j-1].rgbtRed;
                green += temp[i-1][j-1].rgbtGreen;
                blue += temp[i-1][j-1].rgbtBlue;
                count++;
            }

            if ((i - 1 >= 0 && j + 1 >= 0) && (i - 1 >= 0 && j + 1 < width))
            {
                red += temp[i-1][j+1].rgbtRed;
                green += temp[i-1][j+1].rgbtGreen;
                blue += temp[i-1][j+1].rgbtBlue;
                count++;
            }

            if ((i + 1 >= 0 && j >= 0) && (i + 1 < height && j >= 0))
            {
                red += temp[i+1][j].rgbtRed;
                green += temp[i+1][j].rgbtGreen;
                blue += temp[i+1][j].rgbtBlue;
                count++;
            }

            if ((i + 1 >= 0 && j - 1 >= 0) && (i + 1 < height && j - 1 >= 0))
            {
                red += temp[i+1][j-1].rgbtRed;
                green += temp[i+1][j-1].rgbtGreen;
                blue += temp[i+1][j-1].rgbtBlue;
                count++;
            }

            if ((i + 1 >= 0 && j + 1 >= 0) && (i + 1 < height && j + 1 < width))
            {
                red += temp[i+1][j+1].rgbtRed;
                green += temp[i+1][j+1].rgbtGreen;
                blue += temp[i+1][j+1].rgbtBlue;
                count++;
            }

            image[i][j].rgbtRed = round(red / (count * 1.0));
            image[i][j].rgbtGreen = round(green / (count * 1.0));
            image[i][j].rgbtBlue = round(blue / (count * 1.0));
        }
        return;
    }
    
   

