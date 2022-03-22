#include<stdio.h>
#include<stdlib.h>
#include<cs50.h>
#include<ctype.h>
#include<string.h>

int main(int argc,string argv[])
{
    if (argc != 2)
    {
        printf("Usage : ./caeser");
        return 1;
    }

    for (int k=0; k<strlen(argv[1]); k++)
    {
        if (isalpha(argv[1][k]))
        {

        printf("Usage : ./caeser \n");
        return 1;
        }
    }

    int k = atoi(argv[1])%26;
    string p= get_string("Plaintext : ");

    printf("ciphertext : ");

    for (int i=0; i<strlen(p); i++)
    {
        if(!isalpha(p[i]))
        {
            printf("%c",p[i]);
            continue;
        }
        int aoff=isupper(p[i]) ? 65:97;

        int pi=p[i]-aoff;
        int ci= (pi+k)%26;

        printf("%c",ci+aoff);
    }
    printf("\n");
    return 0;
}

