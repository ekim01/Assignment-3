#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum BOOL { false, true } Boolean;

// Linked list node definition
typedef struct NODE Node;

struct NODE
{
  char *string;
  Node *next;
};

static Node *top = NULL;
static int numNodes = 0;
 
// used to track where we are for the list traversal methods
static Node *traverseNode = NULL;

int size( )
{
    if(numNodes >=0)
    {
        assert(numNodes >= 0);
        return numNodes;
    }else
    {
        return -1;
    }
}
    
// add an element to the beginning of the linked list
Boolean insert( char const * const new_string )
{
  Boolean rc = true;
  Node *newNode = NULL;
  
  newNode = (Node *)malloc( sizeof( Node ) );
  
  newNode->next = top;
  top = newNode;
  
  // note that we need to have space for the string as well!
  //make sure node string is empty and we're not replacing something
  if(newNode->string == NULL)
  {
    assert(newNode->string == NULL);
    newNode->string = (char *)malloc( strlen(new_string) + 1 );
    strcpy( newNode->string, new_string );
    if(strcmp(newNode->string,new_string))
    {
        assert(strcmp(newNode->string,new_string));
        numNodes++;
    }else
    {
        rc = false;
    }
  }else
  {
      rc = false;
  }
  return rc;
}


// remove an element with the given string
Boolean delete( char const * const target )
{
  Boolean deleted = false;
  Node *curr = top;
  Node *prev = NULL;
  
  while ( curr != NULL && strcmp( target, curr->string ) != 0 )
  {
    prev = curr;
    curr = curr->next;
  }

  //check to make sure we've actually found the target
  if(strcmp(target,curr->string))
  {
    assert(strcmp(target,curr->string));  
    if ( curr != NULL )
    {
        if( prev != NULL )
        {
         prev->next = curr->next;
        }else
        {
         top = curr->next;
        }
        free( curr->string );
        free( curr );
        deleted = true;
        numNodes--;
    }
  }
  
  return deleted;
}

// tells us whether or not the given string is in the list
Boolean search( char const * const target )
{
  Boolean found = false;
  Node *curr = top;
  
  while ( curr != NULL && !found )
  {
    if ( strcmp( target, curr->string ) == 0 )
    {
      found = true;
    }
    
    else
    {
      curr = curr->next;
    }
  }
  
  return found;
}


// starts a list traversal by getting the data at top
char * firstItem()
{
  traverseNode = top->next;
  
  return top->string;
}


// gets the data at the current traversal node and increments the traversal
char * nextItem()
{
  char *item = NULL;
  
  // no need to go past the end of the list...
  if ( traverseNode != NULL )
  {
    item = traverseNode->string;
    traverseNode = traverseNode->next;
  }
  
  return item;
}