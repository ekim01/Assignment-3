typedef enum BOOL { false, true } Boolean;

// Linked list node definition
typedef struct NODE Node;

struct NODE
{
  char *string;
  Node *next;
};

//prototypes

int size();

Boolean insert( char const * const new_string );

Boolean delete( char const * const target );

Boolean search( char const * const target );

char * firstItem();

char * nextItem();

void clear();