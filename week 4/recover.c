#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

const int BLOCK_SIZE = 512;
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 2)
    {
        printf("Usage: ./volume IMAGE\n");
        return 1;
    }

    // Open files 
    FILE *raw_file = fopen(argv[1], "r");
    if (raw_file == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }
    
    BYTE buffer[BLOCK_SIZE];
    
    int counter = 0;
    
    FILE *final = NULL;
    
    char *img = malloc(8 * sizeof(char));

    while (fread(&buffer, sizeof(char), BLOCK_SIZE, raw_file))
    {
        // Check first four bytes
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && ((buffer[3] &  0xf0) == 0xe0))
        {
            if (counter == 0)
            {
                sprintf(img, "%03i.jpg", 0);

                final = fopen(img, "w"); 
                
                counter ++;
            }
            
            else
            {
                fclose(final);
                
                sprintf(img, "%03i.jpg", counter);

                final = fopen(img, "w"); 
                
                counter ++;
            }
        
        }     
        
        if (final != NULL)
        {
            fwrite(buffer, sizeof(char), BLOCK_SIZE, final);
        }
    }

    // Close files
    fclose(final);
    fclose(raw_file);
    free(img);
        
    return 0;
}
