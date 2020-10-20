#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>


//Número máximo de candidatos/Max number of candidates
#define MAX 9


// Nome e voto dos condidatos / candidates have name and vote count

typedef struct 
{
    int votes;
    char* name;
}candidate;


//Vetor de candidatos / Array of candidates

candidate candidates[MAX];

//Number of candidates

int candidate_count;

// Function prototypes

bool vote(char* name);
void print_winner(void);

int main(int argc, char* argv[])
{
    //Check for invalid usage
    if(argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }    
    

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximium number of candidate is %i", MAX);
        return 2;
    }

    for(int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count;
    printf("Number of votes: ");
    scanf("%i", &voter_count);

    //Loop over all votes

    for(int j = 0; j < voter_count; j++)
        {
            char* name;

            printf("Vote: ");
            scanf("%s", name);
            
             //Check for invalid vote

            if (!vote(name))
                printf("Invalid Vote.\n");
        }

   

    //Display the Winner
    print_winner();

}

// Update vote totals given a new vote

bool vote (char* name)
{
    for(int i = 0; i < candidate_count; i++)
    {
        if(*candidates[i].name == *name)
            {   
                candidates[i].votes++;
                return 1;         
                
            }
    }   
    
        return 0;
}


// Print the winner(or winners) of the election

void print_winner(void)
{
    //declarando ponteiro pra ponteiro e alocando 10 ponteiros de chars para strings não alocadas
    char **maior;
    maior = malloc(sizeof(char*)*9);
    //alocando as strings

    for(int i = 0; i < 9; i++)
    {
        maior[i] = malloc(sizeof(char)*50);
    }


    
    int baseCase = 0;

    for(int i = 0; i < candidate_count; i++)
    {
        if(candidates[i].votes > baseCase)
                baseCase = candidates[i].votes;        
    } 

        printf("%i\n", baseCase);       

     for(int i = 0; i < candidate_count; i++)
        {
            if(candidates[i].votes == baseCase)
            {
                maior[i] = candidates[i].name;
            }
        }   

    for (int i = 0; i < candidate_count; i++)
    {
        printf("%s\n", maior[i]);
    }
    
    
    //liberar a alocação de memória feita

   

    
    
}