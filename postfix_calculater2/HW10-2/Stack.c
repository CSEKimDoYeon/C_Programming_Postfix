#pragma once
#include "Stack.h"

struct _Stack {
	int _top;
	Element* _elements;
};

Stack* Stack_new() {
	Stack* _this = NewObject(Stack);
	_this->_elements = NewVector(Element, MAX_STACK_SIZE);
	// �迭 ���� �������� ����.
	_this->_top = -1;	//top�� -1�� ����.
	return _this;
}// Stack ��ü ����.

void Stack_delete(Stack* _this) {
	free(_this->_elements);
	free(_this);
}// ���� ��ü �Ҹ�.

Boolean Stack_isEmpty(Stack* _this) {
	return(Stack_size(_this)) == 0;	//size�� 0�϶� empty���� �˷���
}// ������ ����ִ��� �˻�.

Boolean Stack_isFull(Stack* _this) {
	return  Stack_size(_this) == MAX_STACK_SIZE;
}// ������ ���� ���ִ��� �˻�.

int Stack_size(Stack* _this) {
	return (_this->_top + 1);
}//������ ������ ��ȯ.

void Stack_push(Stack* _this, Element anElement) {
	if (!Stack_isFull(_this)) {	//���� ������ �ʴٸ�
		_this->_top++;	//top����
		_this->_elements[_this->_top] = anElement;	//����
	}
}//���ÿ� �ش� ���Ҹ� push

Element Stack_pop(Stack* _this) {
	Element poppedElement;	//poppedElement ����.
	poppedElement = _this->_elements[_this->_top];
	_this->_top--; // �ϳ��� pop ������ ������ 1 ����.
	return poppedElement;
}//�ֻ��� ���Ҹ� return

Element Stack_elementAt(Stack* _this, int aPosition) {

	return _this->_elements[aPosition];

}//���Ҹ� ��ȯ

Element Stack_topElement(Stack* _this) {
	return (_this->_elements[_this->_top]);
}//top ���Ҹ� ��ȯ

void Stack_reset(Stack* _this) {
	_this->_top = -1;
}//������ reset��Ų��.