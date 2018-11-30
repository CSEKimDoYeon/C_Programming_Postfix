#include "common.h"	

#define MAX_STACK_SIZE 5

typedef int Element;
typedef struct _Stack Stack;

Stack* Stack_new();
void Stack_delete(Stack* _this);
Boolean Stack_isEmpty(Stack* _this);
Boolean Stack_isFull(Stack* _this);
int Stack_size(Stack* _this);
void Stack_push(Stack* _this, Element anElement);
Element Stack_pop(Stack* _this);
Element Stack_elementAt(Stack* _this, int aPosition);
Element Stack_topElement(Stack* _this);
void Stack_reset(Stack* _this);



