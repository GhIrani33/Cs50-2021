#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int(" enter a number = ");

    }
    while (n < 1 || n >8);
        
    for (int i = 0; i < n; i++)
    {
        for (int a =(i + 1); a < n; a++)
        {
            printf(" ");
        }


        for (int j = 0; j <= i; j++)
        {
            printf("#");

        }
            
        printf("\n");
    }       
       
}          