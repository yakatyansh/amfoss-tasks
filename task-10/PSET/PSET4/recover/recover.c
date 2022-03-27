#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef uint8_t BYTE;


int main(int argc, char* argv[])
{
    if (argc!=2)
    {
        printf("USAGE: ./recover IMAGE \n");
    }
    // open the file for reading

    FILE *input_file = fopen(argv[1], "r");

    // check that the file input is valid
    if (input_file == NULL)
    {
        printf("could not open file");
        return 2;
    }

    // store blocks of 512 bytes in an array
    unsigned char buffer[512];
    int count_image = 0;

    // file pointer for recovered images
    FILE *output_file = NULL;

    // allocate memory for  filename
    char *filename = malloc(8 * sizeof(char));

    //read the blocks of 512 bytes
    while(fread(buffer, sizeof(char), 512, input_file))
    {
        //check if the bytes indicate the start of a JPEG image
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // write the JPEG filenames
            sprintf(filename,"%03i.jpg",count_image);

            //open output_file for writing
            output_file = fopen(filename,"w");

            //count the number of images
            count_image++;

        }

        // check if output has been used for valid input

        if(output_file != NULL)
        {
            fwrite(buffer, sizeof(char), 512, output_file);
        }
    }
    free(filename);
    fclose(output_file);
    fclose(input_file);

    return 0;


}
