#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

string caesar_cipher();

int main(int argc , string argv [] )
{
    string key=argv[1];
    int key_2 = atoi(argv[1]);

    if ((argc != 2))
    {
        printf("Usage: %s key\n",argv[0]);
        return 1;
    }

    else if (argc==2 && key_2<0)
    {
        printf("Usage: %s key\n",argv[0]);
        return 1;
    }
    else if (argc==2)
    {
        int n = strlen(key);
        int alpha=0;
        int num=0;

        //VALIDATING THE KEY WHEATHER ITS A PROPER NON-NEGATIVE INTEGER.
        for (int j=0 ; j<n ; j++)
        {
            char c=key[j];
            if ((c>='A' && c<='Z') || (c>='a' && c<='z'))
            {
                alpha += 1;
            }
            else
            {
                num+=1;
            }
        }
        if (alpha>=1)
        {
            printf("Usage: %s key\n",argv[0]);
            return 1;
        }
        else
        {
            string plaintext = get_string("plaintext: ");
            string cipher = caesar_cipher(key_2,plaintext); //DEFINED A FUNCTION WHICH GIVES THE PROPER 'CIPHERTEXT'
            printf("ciphertext : %s \n",cipher);
            return 0;
        }

    }
}

string caesar_cipher(int key_2,string plaintext)
{
    int n = strlen(plaintext);
    for (int k=0 ; k<n ; k++)
    {
        char c = plaintext[k];
        if ((c>='A' && c<='Z'))
        {
            int formula=(((c+key_2-65)%26)+65);
            plaintext[k]=formula;
        }
        else if ((c>='a' && c<='z'))
        {
            int formula=(((c+key_2-97)%26)+97);
            plaintext[k]=formula;
        }
    }
    return plaintext;
}
                    //THANKS TO CS50....I LITERALLY PROGRAMMED THIS ON MY OWN !!!!! PS:"Rakshith learned C" ☺☺️☺️

