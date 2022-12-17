#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name ;
    name = get_string("Name:");
    printf("Hello,%s \n",name);
}