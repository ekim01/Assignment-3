#include "engine.h"
#include "table.h"

static char currWord[WORDMAX];
static int smallest = WORDMAX;

void scanDict(FILE input,const char *s)
{
    char word[WORDMAX];

    assert(input != NULL);
    if(input != NULL)
    {
        while(fgets(word,WORDMAX,input))
        {
            assert(word != NULL);
            if(word != NULL)
            {
                if(levenshtein(s,word) < SIMLIMIT)
                {
                    insert(word);  //insert word into our table it is a word we want
                    //check if this is the closest word we have
                    if(levenshtein(s,word) < smallest)
                    {
                        //replace closest word with this
                        currWord = word;
                        smallest = levenshtein(s,word);
                    }
                    assert(strcmp(word,firstItem()) == 0);  //check to make sure it actually went inside table
                }
            }else{
                printf("Reached error with scanning word");
            }
        }
    }
}

char* closestWord()
{
    return currWord;
}

void listWords()
{
    char ans = 'x';
    char word[WORDMAX];

    word = firstItem();
    printf("%s\n",word);  //list the first item in the table
    //list the remaining list items
    
    for(int i = 0; i < LISTAMT-1; i++)
    {
        word = nextItem();
        printf("%s\n",word);
    }
    //tell user to quit with q
    printf("Continue listing words with enter,q then enter to stop \n");
    scanf("%s", ans);
    while(ans != 'q')          //only stop if sent a q
    {
        for(int i = 0; i< LISTAMT; i++)
        {
            word = nextItem();
            if(word == NULL)
            {
                i = LISTAMT+1;
                ans = 'q';
            }else{
                printf("%s",word);
            }
        }
        if(ans != 'q')
        {
            printf("Continue listing words with enter,q then enter to stop \n");
            scanf("%s", ans);
        }
    }
}
