#include <stdio.h>
#include <cs50.h>
int main(void)
{
   int h,i,j,k;
   do
   {
      h=get_int("Height: ");
   }
   while(h<1 || h>8);

   for (i = 0; i < h; i++)
    {
    //left pyramid empty spaces

        for (j = h - 1; j > i; j--)
        {
            printf(" ");
        }

    //left pyramid

        for (k = -1; k < i; k++)
        {
            printf("#");
        }

    printf("\n");

   }
}