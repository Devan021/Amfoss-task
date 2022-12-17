#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

int is_JPEG();

const int MAX=512;

typedef uint8_t BYTE;


int main (int argc , char *argv[])
{
    if (argc>2 || argc == 1)
    {
        printf("Usage: %s image \n",argv[0]);
        return 1;
    }
    FILE *file = fopen(argv[1],"r");
    if  (file == NULL)
    {
        printf("There doesn't Exists an file %s/Could not Open. \n",argv[1]);
        return 1;
    }
    BYTE buffer [MAX];
    int JPEG_file=0;
    char filename[8];
    FILE *img;
    while (fread(buffer,MAX,1,file) == 1)
    {
        if (is_JPEG(buffer)==1)
        {
            if (JPEG_file!=0)
            {
                fclose(img);
            }
            sprintf(filename,"%03i.jpg",JPEG_file++);
            img=fopen(filename,"w");
            fwrite(buffer,MAX,1,img);
        }
        else if (JPEG_file>0)
        {
            fwrite(buffer,MAX,1,img);
        }
    }
}

int is_JPEG(BYTE buffer[])
{
    if (buffer[0]==0xff && buffer[1]==0xd8 && buffer[2]==0xff && (buffer[3] & 0xf0)==0xe0)
    {
        return 1;
    }
    return 0;
}

                   //THANKS TO CS50.......LEARNED HOW TO OPEN,WRITE AND READ A FILE :SMILE ☺