#pragma once
#include "Stack.h"

struct _Stack {
	int _top;
	Element* _elements;
};

Stack* Stack_new() {
	Stack* _this = NewObject(Stack);
	_this->_elements = NewVector(Element, MAX_STACK_SIZE);
	// 배열 또한 동적으로 생성.
	_this->_top = -1;	//top을 -1로 지정.
	return _this;
}// Stack 객체 생성.

void Stack_delete(Stack* _this) {
	free(_this->_elements);
	free(_this);
}// 스택 객체 소멸.

Boolean Stack_isEmpty(Stack* _this) {
	return(Stack_size(_this)) == 0;	//size가 0일때 empty임을 알려줌
}// 스택이 비어있는지 검사.

Boolean Stack_isFull(Stack* _this) {
	return  Stack_size(_this) == MAX_STACK_SIZE;
}// 스택이 가득 차있는지 검사.

int Stack_size(Stack* _this) {
	return (_this->_top + 1);
}//스택의 사이즈 반환.

void Stack_push(Stack* _this, Element anElement) {
	if (!Stack_isFull(_this)) {	//가득 차있지 않다면
		_this->_top++;	//top증가
		_this->_elements[_this->_top] = anElement;	//삽입
	}
}//스택에 해당 원소를 push

Element Stack_pop(Stack* _this) {
	Element poppedElement;	//poppedElement 선언.
	poppedElement = _this->_elements[_this->_top];
	_this->_top--; // 하나를 pop 했으니 사이즈 1 감소.
	return poppedElement;
}//최상위 원소를 return

Element Stack_elementAt(Stack* _this, int aPosition) {

	return _this->_elements[aPosition];

}//원소를 반환

Element Stack_topElement(Stack* _this) {
	return (_this->_elements[_this->_top]);
}//top 원소를 반환

void Stack_reset(Stack* _this) {
	_this->_top = -1;
}//스택을 reset시킨다.