#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int count_letters();
int count_words();
int count_sentences();
int main(void)
{
    string text=get_string("Text: ");
    int countletters=count_letters(text);

    int countwords=count_words(text);
    countwords+=1;

    int countsentences=count_sentences(text);

    float L = (countletters/countwords)*100;
    float S = (countsentences/countwords)*100;

    float formula = (0.0588 * countletters/countwords *100) - (0.296 * countsentences/countwords *100) - 15.8;
    int formula_1=round(formula);
    printf("%f\n",formula);
    if (formula_1 <1 )
    {
        printf("Before Grade 1\n");
    }
    else if (formula_1 >1 && formula_1<16  )
    {
        printf("Grade %i\n",formula_1);
    }
    else if (formula_1 >=16)
    {
        printf("Grade 16+\n");
    }
}

int count_letters(string text)
{
    int countletters=0;
    int n=strlen(text);
    for (int i =0 ; i < n ; i++)
    {
        char c=text[i];
        if ((c>='A' &&  c<='Z') || (c>='a' && c<='z'))
        {
            countletters+=1;
        }
    }
    return countletters;
}

int count_words(string text)
{
    int countwords=0;
    char c;
    int n=strlen(text);
    for (int i=0 ; i < n ; i++)
    {
        c=text[i];
        if (c==' ')
        {
            countwords+=1;
        }
    }
    return countwords;
}

int count_sentences(string text)
{
    int countsentences=0;
    char c;
    int i;
    int n = strlen(text);
    for (i=0 ; i<n ; i++)
    {
        c=text[i];
        if (c=='.' || c=='?' || c=='!')
        {
            countsentences+=1;
        }
    }
    return countsentences;
}

                         //THANKS TO CS50......SOMEHOW LEARNED C ☺