#include "table.h"
#include <assert.h>
#include <stdio.h>

#define TESTN 50
int main(void)
{
    char ch;
     //test first with an empty table these should fail
     printf("at test 1 \n");
     assert(!delete("hello"));
     assert(!search("hello"));
     assert(!firstItem());
     assert(!nextItem());
     
     //should all fail now try inserting one item in the list
     printf("passed test1 at test 2 \n");
     insert("test");
     assert(!search("hello"));    //shouldn't find hello
     assert(search("test"));
     assert(firstItem());
     assert(!nextItem());
     //add another one to check for nextItem
     insert("hello");
     assert(search("hello"));
     assert(firstItem());
     assert(nextItem());
     //if we're here then everything should have worked fine so test delete
     printf("passed test 2 now test 3 \n");
     delete("hello");
     delete("test");
     assert(!firstItem());
     assert(!nextItem());
     assert(!search("test"));
     //now test a list of size 50 with different strings
     printf("passed test 3 now test 4 \n");
     for(int i = 0; i < TESTN ; i++)
     {
         ch = i +'0';
         insert(&ch);
     }
     assert(firstItem());
     assert(nextItem());
     for(int k = 0; k < 4; k++)
     {
         ch = (k*(TESTN/5)) + '0';
         assert(search(&ch));
         delete(&ch);
     }
     for(int j = 0; j < 4; j++)
     {
         ch = (j*(TESTN/5)) + '0';
         assert(!search(&ch));
     }
     assert(firstItem());
     assert(nextItem());
     printf("test done \n");

    return 0;
}
