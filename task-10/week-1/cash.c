#include <cs50.h>
#include <math.h>
#include <stdio.h>

int count = 0;

int main(void)
{
    float cash ;
    do
    {
        cash=get_float("Change Owned: ");
    }
    while(cash <= 0);

    int cents=round(cash * 100);
    while (cents>=25)
    {
      cents-=25;
      count+=1;
    }
    while (cents>=10)
    {
      cents-=10;
      count+=1;
    }
    while(cents >=5)
    {
      cents-=5;
      cents+=1;
    }
    while (cents >=1)
    {
      cents-=1;
      count+=1;
    }

    printf("%i\n ",count);
}