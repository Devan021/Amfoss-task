#include <stdio.h>
#include <cs50.h>
#include <string.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATE 9

int preferences[MAX_VOTERS][MAX_CANDIDATE];

//FUNCTIONS PROTOTYPES;
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min();
bool is_tie();
void eliminate(int min);

int count_cand;
int voter_count;

typedef struct
{
    string name ;
    int votes ;
    bool eliminated ;
}
candidates;

candidates candidate[MAX_CANDIDATE];


int main(int argc , string argv[])
{
    count_cand=argc-1;
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }
    else if(count_cand > MAX_CANDIDATE)
    {
        printf("The Maximum no.of candidates are %i\n",MAX_CANDIDATE);
        return 2;
    }
    for (int i = 0; i < count_cand; i++)
    {
        candidate[i].name = argv[i + 1];
        candidate[i].votes = 0;
        candidate[i].eliminated = false;
    }

    voter_count=get_int("No.of Voters:");

    if(voter_count > MAX_VOTERS)
    {
        printf("The Maximum no.of voters can be %i\n",MAX_VOTERS);
        return 3;
    }
    for (int i =0 ; i < voter_count ; i++)
    {
        for (int j = 0 ; j<count_cand ; j++)
        {
            string name = get_string ("Rank %i:",j+1);
            if (vote(i,j,name) == false )
            {
                printf("Invalid Vote. \n");
                return 4;
            }
        }
        printf("\n");
    }
    while(true)
    {
        tabulate();

        bool won = print_winner();
        if (won == true)
        {
            break;
        }

        int small = find_min();
        bool tie=is_tie(small);

        if (tie==true)
        {
            for (int i = 0; i < count_cand; i++)
            {
                if (candidate[i].eliminated==false)
                {
                    printf("%s\n", candidate[i].name);
                }
            }
            break;
        }
        eliminate(small);
        for (int i = 0; i < count_cand; i++)
        {
            candidate[i].votes = 0;
        }
    }
    return 0;
}

bool vote(int voter , int rank , string name)
{
    for (int i = 0 ; i<count_cand ; i++)
    {
        if (strcmp(name,candidate[i].name)==0)
        {
            preferences[voter][rank] = i;
            return true;
        }
    }
    return false ;
}

void tabulate (void)
{
    for (int i=0 ; i<voter_count ; i++)
    {
        for (int j = 0 ; j<count_cand ; j++)
        {
            if (candidate[preferences[i][j]].eliminated==false)
            {
                candidate[preferences[i][j]].votes+=1;
            }
        }
    }
    return ;
}

bool print_winner(void)
{
    for  (int i = 0 ; i<voter_count ; i++)
    {
        if (candidate[i].votes > (voter_count/2))
        {
            printf("%s \n",candidate[i].name);
            return true;
        }
    }
    return false ;
}

int find_min(void)
{
    int small = candidate[0].votes;
    for (int i = 0 ; i<count_cand ; i++)
    {
        if ((candidate[i].votes < small) && (candidate[i].eliminated == false) )
        {
            small = candidate[i].votes;
        }
    }
    return small;
}

bool is_tie(int small)
{
    int elimination = 0 ;
    int small_count=0;
    for (int i=0 ; i<count_cand ; i++)
    {
        if (candidate[i].eliminated == false)
        {
            elimination +=1;
        }
        else if (candidate[i].votes==small)
        {
            small_count+=1;
        }
    }
    if (elimination == small_count)
    {
        return true;
    }
    return false ;
}

void eliminate(int small)
{
    for (int i =0 ; i<count_cand ; i++)
    {
        if (candidate[i].votes == small)
        {
            candidate[i].eliminated = true;
        }
    }
    return ;
}
                 //THANKS TO CS50.......Learned CHEHHEHE