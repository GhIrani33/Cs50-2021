#include "helpers.h"
#include <math.h>
#include <stdio.h>


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            float average = ((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            average = round(average);
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }

    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            float Red = ((0.393 * image[i][j].rgbtRed) + (0.769 * image[i][j].rgbtGreen) + (0.189 * image[i][j].rgbtBlue));
            float Green = ((0.349 * image[i][j].rgbtRed) + (0.686 * image[i][j].rgbtGreen) + (0.168 * image[i][j].rgbtBlue));
            float Blue = ((0.272 * image[i][j].rgbtRed) + (0.534 * image[i][j].rgbtGreen) + (0.131 * image[i][j].rgbtBlue));

            Red = round(Red);
            image[i][j].rgbtRed = Red;

            Green = round(Green);
            image[i][j].rgbtGreen = Green;

            Blue = round(Blue);
            image[i][j].rgbtBlue = Blue;

            if (Red > 255.0)
            {
                image[i][j].rgbtRed = 255.0;
            }

            if (Green > 255.0)
            {
                image[i][j].rgbtGreen = 255.0;
            }

            if (Blue > 255.0)
            {
                image[i][j].rgbtBlue = 255.0;
            }

        }

    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    void swap(RGBTRIPLE * a, RGBTRIPLE * b);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            if ((width % 2) == 0)
            {
                if (j < (width / 2))
                {
                    swap(&image[i][j], &image[i][(width - 1) - j]);
                }
            }

            else
            {
                if (j < (width / 2))
                {
                    swap(&image[i][j], &image[i][(width - 1) - j]);
                }
            }
        }
    }
    return;
}
void swap(RGBTRIPLE *a, RGBTRIPLE *b)
{
    RGBTRIPLE tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}


// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    for (int a = 0; a < height; a++)
    {
        for (int b = 0; b < width; b++)
        {
            copy[a][b] = image[a][b];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == (height - 1))
            {
                if (j == (width - 1))
                {
                    float Red = ((copy[i][j].rgbtRed + copy[i - 1][j - 1].rgbtRed + copy[i - 1][j].rgbtRed + copy[i][j - 1].rgbtRed) / 4.0);
                    float Green = ((copy[i][j].rgbtGreen + copy[i - 1][j - 1].rgbtGreen + copy[i - 1][j].rgbtGreen + copy[i][j - 1].rgbtGreen) / 4.0);
                    float Blue = ((copy[i][j].rgbtBlue + copy[i - 1][j - 1].rgbtBlue + copy[i - 1][j].rgbtBlue + copy[i][j - 1].rgbtBlue) / 4.0);
                    Red = round(Red);
                    Green = round(Green);
                    Blue = round(Blue);
                    image[i][j].rgbtRed = Red;
                    image[i][j].rgbtGreen = Green;
                    image[i][j].rgbtBlue = Blue;
                }    
                else if (j == 0)
                {
                    float Red = ((copy[i][j].rgbtRed + copy[i - 1][j].rgbtRed + copy[i - 1][j + 1].rgbtRed + copy[i][j + 1].rgbtRed) / 4.0);
                    float Green = ((copy[i][j].rgbtGreen + copy[i - 1][j].rgbtGreen + copy[i - 1][j + 1].rgbtGreen + copy[i][j + 1].rgbtGreen) / 4.0);
                    float Blue = ((copy[i][j].rgbtBlue + copy[i - 1][j].rgbtBlue + copy[i - 1][j + 1].rgbtBlue + copy[i][j + 1].rgbtBlue) / 4.0);
                    Red = round(Red);
                    Green = round(Green);
                    Blue = round(Blue);
                    image[i][j].rgbtRed = Red;
                    image[i][j].rgbtGreen = Green;
                    image[i][j].rgbtBlue = Blue; 
                }
                else if (0 < j < (width - 1))
                {
                    float Red = ((copy[i][j].rgbtRed + copy[i - 1][j - 1].rgbtRed + copy[i - 1][j].rgbtRed + copy[i - 1][j + 1].rgbtRed + copy[i][j -
                                  1].rgbtRed + copy[i][j + 1].rgbtRed) / 6.0);
                    float Green = ((copy[i][j].rgbtGreen + copy[i - 1][j - 1].rgbtGreen + copy[i - 1][j].rgbtGreen + copy[i - 1][j + 1].rgbtGreen +
                                    copy[i][j - 1].rgbtGreen + copy[i][j + 1].rgbtGreen) / 6.0);
                    float Blue = ((copy[i][j].rgbtBlue + copy[i - 1][j - 1].rgbtBlue + copy[i - 1][j].rgbtBlue + copy[i - 1][j + 1].rgbtBlue + copy[i][j
                                   - 1].rgbtBlue + copy[i][j + 1].rgbtBlue) / 6.0);
                    Red = round(Red);
                    Green = round(Green);
                    Blue = round(Blue);
                    image[i][j].rgbtRed = Red;
                    image[i][j].rgbtGreen = Green;
                    image[i][j].rgbtBlue = Blue;
                }
            }    
            else if (i == 0)
            {
                if (j == 0)
                {
                    float Red = ((copy[i][j].rgbtRed + copy[i][j + 1].rgbtRed + copy[i + 1][j].rgbtRed + copy[i + 1][j + 1].rgbtRed) / 4.0);
                    float Green = ((copy[i][j].rgbtGreen + copy[i][j + 1].rgbtGreen + copy[i + 1][j].rgbtGreen + copy[i + 1][j + 1].rgbtGreen) / 4.0);
                    float Blue = ((copy[i][j].rgbtBlue + copy[i][j + 1].rgbtBlue + copy[i + 1][j].rgbtBlue + copy[i + 1][j + 1].rgbtBlue) / 4.0);
                    Red = round(Red);
                    Green = round(Green);
                    Blue = round(Blue);
                    image[i][j].rgbtRed = Red;
                    image[i][j].rgbtGreen = Green;
                    image[i][j].rgbtBlue = Blue;
                }
                else if (j == (width - 1))
                {
                    float Red = ((copy[i][j].rgbtRed + copy[i][j - 1].rgbtRed + copy[i + 1][j - 1].rgbtRed + copy[i + 1][j].rgbtRed) / 4.0);
                    float Green = ((copy[i][j].rgbtGreen + copy[i][j - 1].rgbtGreen + copy[i + 1][j - 1].rgbtGreen + copy[i + 1][j].rgbtGreen) / 4.0);
                    float Blue = ((copy[i][j].rgbtBlue + copy[i][j - 1].rgbtBlue + copy[i + 1][j - 1].rgbtBlue + copy[i + 1][j].rgbtBlue) / 4.0);
                    Red = round(Red);
                    Green = round(Green);
                    Blue = round(Blue);
                    image[i][j].rgbtRed = Red;
                    image[i][j].rgbtGreen = Green;
                    image[i][j].rgbtBlue = Blue; 
                }
                else if (0 < j < (width - 1))
                {
                    float Red = ((copy[i][j].rgbtRed + copy[i][j - 1].rgbtRed + copy[i][j + 1].rgbtRed + copy[i + 1][j - 1].rgbtRed + copy[i +
                                  1][j].rgbtRed + copy[i + 1][j + 1].rgbtRed) / 6.0);
                    float Green = ((copy[i][j].rgbtGreen + copy[i][j - 1].rgbtGreen + copy[i][j + 1].rgbtGreen + copy[i + 1][j - 1].rgbtGreen + copy[i +
                                    1][j].rgbtGreen + copy[i + 1][j + 1].rgbtGreen) / 6.0);
                    float Blue = ((copy[i][j].rgbtBlue + copy[i][j - 1].rgbtBlue + copy[i][j + 1].rgbtBlue + copy[i + 1][j - 1].rgbtBlue + copy[i +
                                   1][j].rgbtBlue + copy[i + 1][j + 1].rgbtBlue) / 6.0);
                    Red = round(Red);
                    Green = round(Green);
                    Blue = round(Blue);
                    image[i][j].rgbtRed = Red;
                    image[i][j].rgbtGreen = Green;
                    image[i][j].rgbtBlue = Blue;
                }
            }
            else if (0 < i < (height - 1))
            {
                if (j == 0)
                {
                    float Red = ((copy[i][j].rgbtRed + copy[i - 1][j].rgbtRed + copy[i - 1][j + 1].rgbtRed + copy[i][j + 1].rgbtRed + copy[i +
                                  1][j].rgbtRed + copy[i + 1][j + 1].rgbtRed) / 6.0);
                    float Green = ((copy[i][j].rgbtGreen + copy[i - 1][j].rgbtGreen + copy[i - 1][j + 1].rgbtGreen + copy[i][j + 1].rgbtGreen + copy[i +
                                    1][j].rgbtGreen + copy[i + 1][j + 1].rgbtGreen) / 6.0);
                    float Blue = ((copy[i][j].rgbtBlue + copy[i - 1][j].rgbtBlue + copy[i - 1][j + 1].rgbtBlue + copy[i][j + 1].rgbtBlue + copy[i +
                                   1][j].rgbtBlue + copy[i + 1][j + 1].rgbtBlue) / 6.0);
                    Red = round(Red);
                    Green = round(Green);
                    Blue = round(Blue);
                    image[i][j].rgbtRed = Red;
                    image[i][j].rgbtGreen = Green;
                    image[i][j].rgbtBlue = Blue; 
                }
                else if (j == (width - 1))
                {
                    float Red = ((copy[i][j].rgbtRed + copy[i - 1][j - 1].rgbtRed + copy[i - 1][j].rgbtRed + copy[i][j - 1].rgbtRed + copy[i + 1][j -
                                  1].rgbtRed + copy[i + 1][j].rgbtRed) / 6.0);
                    float Green = ((copy[i][j].rgbtGreen + copy[i - 1][j - 1].rgbtGreen + copy[i - 1][j].rgbtGreen + copy[i][j - 1].rgbtGreen + copy[i +
                                    1][j - 1].rgbtGreen + copy[i + 1][j].rgbtGreen) / 6.0);
                    float Blue = ((copy[i][j].rgbtBlue + copy[i - 1][j - 1].rgbtBlue + copy[i - 1][j].rgbtBlue + copy[i][j - 1].rgbtBlue + copy[i + 1][j
                                   - 1].rgbtBlue + copy[i + 1][j].rgbtBlue) / 6.0);
                    Red = round(Red);
                    Green = round(Green);
                    Blue = round(Blue);
                    image[i][j].rgbtRed = Red;
                    image[i][j].rgbtGreen = Green;
                    image[i][j].rgbtBlue = Blue;
                }
                else if (0 < j < (width - 1))
                {
                    float Red = ((copy[i][j].rgbtRed + copy[i - 1][j - 1].rgbtRed + copy[i - 1][j].rgbtRed + copy[i - 1][j + 1].rgbtRed + copy[i][j -
                                  1].rgbtRed + copy[i][j + 1].rgbtRed + copy[i + 1][j - 1].rgbtRed + copy[i + 1][j].rgbtRed + copy[i + 1][j + 1].rgbtRed) / 9.0);
                    float Green = ((copy[i][j].rgbtGreen + copy[i - 1][j - 1].rgbtGreen + copy[i - 1][j].rgbtGreen + copy[i - 1][j + 1].rgbtGreen +
                                    copy[i][j - 1].rgbtGreen + copy[i][j + 1].rgbtGreen + copy[i + 1][j - 1].rgbtGreen + copy[i + 1][j].rgbtGreen + copy[i + 1][j +
                                            1].rgbtGreen) / 9.0);
                    float Blue = ((copy[i][j].rgbtBlue + copy[i - 1][j - 1].rgbtBlue + copy[i - 1][j].rgbtBlue + copy[i - 1][j + 1].rgbtBlue + copy[i][j
                                   - 1].rgbtBlue + copy[i][j + 1].rgbtBlue + copy[i + 1][j - 1].rgbtBlue + copy[i + 1][j].rgbtBlue + copy[i + 1][j + 1].rgbtBlue) /
                                  9.0);
                    Red = round(Red);
                    Green = round(Green);
                    Blue = round(Blue);
                    image[i][j].rgbtRed = Red;
                    image[i][j].rgbtGreen = Green;
                    image[i][j].rgbtBlue = Blue;
                }
            }
        }
    }
    return;
}