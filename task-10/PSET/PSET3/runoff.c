#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and c
#define MAX_VOTERS 100
#define MAX_c 9

// preferences[i][j] is jth preference for voter i (2D array)
int preferences[MAX_VOTERS][MAX_c];

// encapsulation of name, no of votes and eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of c
candidate c[MAX_c];

// Numbers of voters and c
int voter_count;
int candidate_count;

// declaration of different function to be used here
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid input
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // ensure that the input is less than max
    candidate_count = argc - 1;
    if (candidate_count > MAX_c)
    {
        printf("Maximum number of c is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        c[i].name = argv[i + 1];
        c[i].votes = 0;
        c[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining c
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place c
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!c[i].eliminated)
                {
                    printf("%s\n", c[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            c[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, c[i].name) == 0)
        {
            preferences[voter][rank] = i;
            return true;
        }
    }
    return false;
}

// Tabulate votes for non-eliminated c
void tabulate(void)
{
    // TODO
    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (c[preferences[i][j]].eliminated == false)
            {
                c[preferences[i][j]].votes++;
                break;
            }
        }

    }
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        string max = c[i].name;
        if (c[i].votes > voter_count / 2)
        {
            printf("%s\n", max);
            return true;
        }
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    int minv = voter_count;
    for (int i = 0; i < candidate_count; i++)
    {
        if (c[i].eliminated == false && c[i].votes < minv)
        {
            minv = c[i].votes;
        }
    }
    return minv;
}

// Return true if the election is tied between all c, false otherwise
bool is_tie(int min)
{
   for (int i = 0; i < candidate_count; i++)
    {
        if (c[i].eliminated == false && c[i].votes != min)
        {
            return false;
        }
    }
    return true;
}

// Eliminate the candidate (or c) in last place
void eliminate(int min)
{
    for (int i = 0; i < candidate_count; i++)

        if (c[i].votes == min)
        {
            c[i].eliminated = true;
        }
    return;
}