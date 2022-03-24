#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max candidates defined globally as 9
#define MAX 9

// Encapsulating a name and number of votes in a user defined struture called candidates
typedef struct
{
    string name;
    int votes;
}
candidate;

// here we are initializing an array of 9 candidates
candidate c[MAX];

// Number of candidates
int c_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    c_count = argc - 1;
    if (c_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < c_count; i++)
    {
        c[i].name = argv[i + 1];
        c[i].votes = 0;
    }

    int v_c = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < v_c; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{

    for (int i = 0; i < c_count; i++)
    {
        if (strcmp(c[i].name, name) == 0)
        {
            c[i].votes++;
            return true;
        }
    }

    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{

    int maximumv = 0;

    for (int i = 0; i < c_count; i++)
    {
        if (c[i].votes > maximumv)
        {
            maximumv = c[i].votes;
        }
    }

    for (int i = 0; i < c_count; i++)
    {
        if (c[i].votes == maximumv)
        {
            printf("%s\n", c[i].name);
        }
    }

    return;
}
