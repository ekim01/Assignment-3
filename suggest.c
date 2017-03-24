#include "engine.h"
#include "table.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char word[WORDMAX];
    char answer;
    FILE* input;

    assert(argc > 1);
    assert(argv[1] != NULL);

    if(argc > 1 && argv[1] != NULL)
    {
        input = fopen(argv[1], "r");
        assert(input != NULL);
        if(input != NULL)
        {
            printf("what word should i check? ");
            scanf("%s", word);
            printf("%s\n",word);
            printf("Did you mean... %s \n", closestWord());
            printf("There are %d other similar words, would you like to see them? (y\n)", size());
            scanf("%c",&answer);
            if(answer == 'y' || answer == 'n')
            {
                if(answer == 'y')
                {
                    listWords();
                }
            }else{
                printf("answer must either be y/n");
            }

        }
        else
        {
            printf( "Could not open %s.\n", argv[1] );
        }
    }
}