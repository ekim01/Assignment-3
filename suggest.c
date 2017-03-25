#include "engine.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE* input;

    assert(argc > 1);
    assert(argv[1] != NULL);
    if(argc > 1 && argv[1] != NULL)
    {
        input = fopen(argv[1], "r");
        assert(input != NULL);
        if(input != NULL)
        {
            runProgram(input);
        }
        else
        {
            printf( "Could not open %s.\n", argv[1] );
        }
    }
}