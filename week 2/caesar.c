#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char POINT1[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
char POINT2[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int main(int argc, string argv[])
{
    int k;
    if (argc == 2)
    {   
        printf("sucsses\n");
        
        for (int i = 1; i < argc; i++)
        {
            for (int j = 0, n = strlen(argv[i]); j < n; j++)
            {
                printf("%c\n", argv[i][j]);
                if (isdigit(argv[i][j]))
                {
                    int key = atoi(argv[1]);
                    printf("%i\n", key);
                    
                }
                else
                {
                    printf("useg :./caesar2 key\n");
                    return 1;
                }
            }

        }
   
        
    }
    else
    {
        printf("useg :./caesar key\n");
        return 1;
    }
    
    int key = atoi(argv[1]);
    printf("%i\n", key);

    string p = get_string("plaintext: ");

    printf("ciphertext: ");
    for (int i = 0; i < strlen(p); i++)
    {
        if (isalpha(p[i]))
        {
            if (isupper(p[i]))
            {
                int c = ((p[i] - 65) + key) % 26;
                printf("%c", POINT1[c]);
            }
            
            if (islower(p[i]))
            {
                int c = ((p[i] - 97) + key) % 26;
                printf("%c", POINT2[c]);
            }
        }
        
        else
        {
            printf("%c", p[i]);
        }
        
    }
    printf("\n");
    return 0;
}