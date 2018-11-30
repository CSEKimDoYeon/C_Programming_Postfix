#include "Postfix.h"
#include <string.h>

Postfix* Postfix_new(int givenMaxNumberOfTokens) {
	//Postfix 객체 생성
	Postfix* _this = NewObject(Postfix);
	_this->_maxNumberOfTokens = givenMaxNumberOfTokens;
	_this->_expression = NewVector(char, givenMaxNumberOfTokens);
	// 배열도 동적으로 생성해준다.
	_this->_operandStack = Stack_new(givenMaxNumberOfTokens);
	return _this;
}

void Postfix_delete(Postfix* _this) {
	// Postfix 객체 삭제
	Stack_delete(_this->_operandStack);	
	free(_this->_expression);	
	free(_this);	
}


Boolean Postfix_evaluate(Postfix* _this) {
	int operand, operand1, operand2, calculated;
	char currentToken;
	int i = 0;
	Stack_reset(_this->_operandStack);	// 한번 계산 할 때마다 스택을 초기화.
	while (_this->_expression[i] != '\0') {		
		currentToken = _this->_expression[i];	
		if (currentToken >= '0' && currentToken <= '9') {	
			operand = (currentToken - '0');		
			Stack_push(_this->_operandStack, operand);	
		}
		else {
			if (currentToken == '+') {	//덧셈일 때
				operand2 = Stack_pop(_this->_operandStack);
				operand1 = Stack_pop(_this->_operandStack);	
				calculated = operand1 + operand2;	
				Stack_push(_this->_operandStack, calculated);	
			}
			else if (currentToken == '-') {	//뺄셈일 때
				operand2 = Stack_pop(_this->_operandStack);
				operand1 = Stack_pop(_this->_operandStack);	
				calculated = operand1 - operand2;	
				Stack_push(_this->_operandStack, calculated);	
			}
			else if (currentToken == '*') {	//곱셈일 때
				operand2 = Stack_pop(_this->_operandStack);
				operand1 = Stack_pop(_this->_operandStack);	
				calculated = operand1 * operand2;	
				Stack_push(_this->_operandStack, calculated);	
			}
			else if (currentToken == '/') {	//나누기일 때
				operand2 = Stack_pop(_this->_operandStack);
				operand1 = Stack_pop(_this->_operandStack);	
				calculated = operand1 / operand2;	
				Stack_push(_this->_operandStack, calculated);
			}
			else if (currentToken == '%') {	//나머지연산일 때
				operand2 = Stack_pop(_this->_operandStack);
				operand1 = Stack_pop(_this->_operandStack);	
				calculated = operand1 % operand2;
				Stack_push(_this->_operandStack, calculated);	
			}
		}
		Postfix_showTokenAndStack(_this, currentToken);	// 해당 스택의 정보를 전부 출력.
		i++;
	}
	_this->_evaluatedValue = Stack_pop(_this->_operandStack); // 계산한 값을 스택에서 pop
	return true;	
}

void Postfix_setExpression(Postfix* _this, char* anExpression) {
	strcpy(_this->_expression, anExpression); // 입력받은 수식을 복사.
}


int Postfix_evaluatedValue(Postfix* _this) {
	return (_this->_evaluatedValue);
} // 계산 결과 반환.

void Postfix_showTokenAndStack(Postfix* _this, char Token) {
	char element; // element 선언.
	AppIO_out_showToken(Token);	// 첫 번 째 토큰을 보여준다.
	AppIO_out_bottomOfStack();	
	for (int i = 0; i<Stack_size(_this->_operandStack); i++) {	//스택의 크기만큼 반복
		element = Stack_elementAt(_this->_operandStack, i);	//스택의 i번째 원소
		AppIO_out_element(element);	// 해당 원소 출력.
	}
	AppIO_out_topOfStack();	
	AppIO_out_newLine();	
}