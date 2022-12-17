#include <cs50.h>
#include <string.h>
#include <stdio.h>

const int MAX=9;

bool vote();
void print_winner();

int count_cand;

typedef struct
{
    string name;
    int vote;
}
candidates;

candidates candidate[MAX];

int main(int argc , string argv[])
{

    count_cand=argc-1;

    if (argc<2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }
    else if (count_cand>MAX)
    {
        printf("The Max input is %i \n",MAX);
        return 1;
    }
    else if ((count_cand<=MAX) && (argc>=2))
    {
        for (int i = 0 ; i<count_cand ; i++)
        {
            candidate[i].name=argv[i+1];
            candidate[i].vote=0;

        }
        int voter_count=get_int("No.of Voters:");
        for (int j = 0 ; j<voter_count ; j++)
        {
            string vote_name=get_string("Vote For :");
            bool votee=vote(vote_name,count_cand);
            if (votee != true)
            {
                printf("Invalid vote. \n");
            }
        }
        print_winner();
    }
}

bool vote(string vote_name)
{
    for (int i=0 ; i <count_cand ; i++)
    {
        if (strcmp(vote_name,candidate[i].name)==0)
        {
            candidate[i].vote+=1;
            return true;
        }
    }
    return false;

}

void print_winner(void)
{
    int large=candidate[0].vote;

    for (int i=1 ; i<count_cand ; i++)
    {
        if (candidate[i].vote>large)
        {
            large=candidate[i].vote;

        }
    }
    for (int i = 0 ; i<count_cand ; i++)
    {
        if (large == candidate[i].vote)
        {
            printf("%s \n",candidate[i].name);
        }
    }
    return;

}

                    //THANKS TO CS50.......PS:"Rakshith learned C " LMAO