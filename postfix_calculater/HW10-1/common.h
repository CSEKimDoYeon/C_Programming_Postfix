#include <stdlib.h>

#define NewObject(TYPE) (TYPE*)malloc(sizeof(TYPE))	//객체를 동적으로 생성
#define NewVector(TYPE,SIZE) (TYPE*)malloc(sizeof(TYPE)*SIZE)	//배열을 동적으로 생성

typedef int Boolean;
#define true 1
#define false 0

