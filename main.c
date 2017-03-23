#include "table.h"
#include <assert.h>

#define TESTN 50
int main(void)
{
    char ch;
     //test first with an empty table these should fail
     assert(!delete("hello"));
     assert(!search("hello"));
     assert(firstItem() == NULL);
     assert(nextItem() == NULL);
     //should all fail now try inserting one item in the list
     insert("test");
     assert(!search("hello"));    //shouldn't find hello
     assert(search("test"));
     assert(firstItem() != NULL);
     assert(nextItem() != NULL);
     //if we're here then everything should have worked fine so test delete
     delete("test");
     assert(firstItem() == NULL);
     assert(nextItem() == NULL);
     assert(!search("test"));
     //now test a list of size 50 with different strings
     for(int i = 0; i < TESTN ; i++)
     {
         ch = i +'0';
         insert(ch);
     }
     assert(firstItem() != NULL);
     assert(nextItem() == NULL);
     for(int k = 0; k < 4; k++)
     {
         ch = (k*(TESTN/5)) + '0';
         assert(search(ch));
         delete(search(ch));
     }
     for(int j = 0; j < 4; j++)
     {
         ch = (j*(TESTN/5)) + '0';
         assert(!search(ch));
     }
     assert(firstItem() != NULL);
     assert(nextItem() != NULL);

    return 0;
}
