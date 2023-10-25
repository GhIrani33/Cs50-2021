#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


int main(void)
{
    string text = get_string("text : ");
        
    
    int letters = 0;
    int sentences = 0;
    int words = 0;
    int i;

    for (i = 0; i < strlen(text); i++)
    {
        if (isalpha((text[i])))
        {
            letters = letters + 1;
        }
       
        if (text[i] == ' ')
        {
            words = words + 1;
        }
        
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences = sentences + 1;
        }
    
    }
    words = words + 1;
    
    float L = (letters * 100) / words;
    float S = (sentences * 100) / words;
    
    float index = (0.0588 * L - 0.296 * S - 15.8);
    
    
    int Grade;
    if (index < 1)
    {
        printf(" Before Grade 1\n");
    
    }
        
    if (index >= 1)
    {
        if (index < 16)
        {
            Grade = round(index);
            printf("Grade %i\n", Grade);
        }
    }
    
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
}