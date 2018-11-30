#include "common.h"
#include <stdio.h>

typedef struct _AppIO AppIO;	

struct _AppIO {
	AppIO* _this;
};

AppIO* AppIO_new();
void AppIO_out_startingMessage();
void AppIO_delete(AppIO* _this);
Boolean AppIO_in_postfixExpression(char* _elements);
void AppIO_out_errorInExpression();
void AppIO_out_evaluatedValue(int value);
void AppIO_out_endingMessage();
void AppIO_out_element(int anElement);
void AppIO_out_showToken(char token);
void AppIO_out_topOfStack();
void AppIO_out_bottomOfStack();
void AppIO_out_newLine();

