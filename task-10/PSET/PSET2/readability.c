#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int countlet(string t);
int countwor(string t);
int countsen(string t);
int main(void)
{
    string t = get_string("Type your sentence please:");
    float g = 0.0588 * (100 * (float) countlet(t) / (float) countwor(t)) - 0.296 * (100 * (float) countsen(t) / (float) countwor(t)) - 15.8;

    if (g < 16 && g >= 0)
    {
        printf("Grade %i\n", (int) round(g));
    }
    else if (g >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Before Grade 1\n");
    }
}

int countlet(string text)
{
    int letters = 0;
    for (int i = 0,len = strlen(text); i<len; i++)
    {
        if (isupper(text[i]))
        {
            letters++;
        }
        else if (islower(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

int countwor(string text)
{
    int words = 1;
    for (int j = 0,len = strlen(text); j<len; j++)
    {
        if (text[j]== ' ')
        {
            words++;
        }

    }
    return words;
}

int countsen(string text)
{
    int sen= 0;
    for (int k = 0,len =strlen(text); k<len; k++)
    {
        if (text[k] == '.' || text[k] == '!' || text[k] == '?')
        {
            sen++;
        }
    }
    return sen;
}
 
