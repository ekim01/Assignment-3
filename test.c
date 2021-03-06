#include "engine.h"
#include <assert.h>
#include <stdio.h>

int main(int argc,char *argv[])
{
    FILE* input;

    assert(argc > 1);
    assert(argv[1] != NULL);

    if(argc > 1 && argv[1] != NULL)
    {
        //test functions that need a table for an empty table
        printf("tests for empty table and empty input \n");
        assert(!closestWord());
        assert(listWords());  //should say its an empty list
        assert(scanDict(input,"hello")); //should say its a null input
        assert(runProgram())   //could not open FILE
        //check functions that only need table for one item
        printf("tests for one item in table \n");
        insert("hello");
        assert(listWords()); //should print hello and thats it
        reset();
        assert(size() == 0);  //everything should be empty again;
        printf("test for 12 items");
        insert("hell");
        insert("bell");
        insert("tear");
        insert("torn");
        insert("tree");
        insert("crow");
        insert("brow");
        insert("lose");
        insert("nine");
        insert("ten");
        insert("boom");
        insert("pew");
        listWords();      //should list all of them
        reset();
        input = fopen(argv[1], "r");
        assert(input != NULL);
        if(input != NULL)
        {
            //start testing with input now recommended to use dict 
            //will be hard to test runProgram, runProgram will be final test just to see if its working properly
            printf("test for proper input with empty string \n");
            scanDict(input,"");  //empty string
            listWords();   //check what it shows, it should show basically every 5 letter listWord
            assert(strlen(closestWord()) =< 1 );  //there should be a 1 letter like A which should have a levenshtein of 1
            reset();
            assert(size() == 0);
            printf("test for proper input with extreme string \n");
            scanDict(input,"asfdaiouhgrsnsfunaosfiensf");  //check for extreme this shouldn't find anyhting similar
            listWords();   //should be empty list because scan shouldn't have found anything
            assert(!closestWord());  //shouldnt be a word even close to this 
            reset();
            assert(size() == 0);  // reset again and check to make sure its been reset
            printf("test for proper input with a normal string \n");
            scanDict(input,"hello");  //check for a normal entry
            listWords();      //check to make sure this is working as expected 
            assert(closestWord());    //check that closest word actually sends something
            reset();
            assert(size() == 0);
            printf("testing seems to have gone well, now runProgram check if all working as expected \n");
            runProgram();
            reset();
        }
        else
        {
            printf( "Could not open %s.\n", argv[1] );
        }
    }
}