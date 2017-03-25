#include "engine.h"
#include "table.h"
#include "levenshtein.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>

static char currWord[WORDMAX];
static int smallest = WORDMAX;

void scanDict(FILE *input,const char *s)
{
    char word[WORDMAX];

    assert(input != NULL);
    if(input != NULL)
    {
        while(fgets(word,WORDMAX,input))
        {               
            assert(*word);
            if(*word)
            {
                if(levenshtein(s,word) <= SIMLIMIT)
                {
                    insert(word);  //insert word into our table it is a word we want
                    //check if this is the closest word we have
                    if(levenshtein(s,word) < smallest)
                    {
                        //replace closest word with this
                        strcpy(currWord,word);
                        smallest = levenshtein(s,word);
                    }
                    assert(strcmp(word,firstItem()) == 0);  //check to make sure it actually went inside table
                }
            }else{
                printf("Reached error with scanning word");
            }
        }
    }
    else
    {
        printf("input is null");
    }
}

char* closestWord()
{
    char* word = currWord;
    return word;
}

void listWords()
{
    char ans = 0;
    char* word = NULL;

    word = firstItem();
    printf("%s",word);  //list the first item in the table
    //list the remaining list items
    
    for(int i = 0; i < LISTAMT-1; i++)
    {
        word = nextItem();
        if(word == NULL)
        {
            i = LISTAMT+1;
        }else
        {
            printf("%s",word);
        }
    }
    //tell user to quit with q
    printf("Continue listing words with enter,q then enter to stop \n");
    ans = getchar();  //clear out buffer
    ans = getc(stdin);
    if(ans == 'q' || ans == '\n' || ans == 'r'){
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
              ans = getc(stdin);
          }
      }
    }
    else
    {
      printf("Must use enter or q enter\n");
    }
}

void reset()
{
    clear();
    smallest = WORDMAX;
}

void runProgram(FILE *input)
{
    char word[WORDMAX];
    char answer;

    assert(input != NULL);
    if(input != NULL)
    {
        printf("what word should i check? ");
        scanf("%s", word);
        printf("%s\n",word);
        scanDict(input,word);
        if(size() < 2)
        {
            //theres only one similar word just ask if its that
            if(size() == 1)
            {
                printf("Did you mean... %s \n",closestWord());
                printf("There are no other similar words \n");
            }
            if(size() == 0)     //no similar words found can't do much
            {
                printf("No similar words found \n");
            }
        }else{
            printf("Did you mean... %s \n", closestWord());
            printf("There are %d other similar words, would you like to see them? (y/n)", size());
            scanf(" %c",&answer);
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
        reset();
    }else
    {
        printf("Could not open file \n");
    }

}