typedef enum BOOL { false, true } Boolean;

// Linked list node definition
typedef struct NODE Node;

struct NODE
{
  char *string;
  Node *next;
};