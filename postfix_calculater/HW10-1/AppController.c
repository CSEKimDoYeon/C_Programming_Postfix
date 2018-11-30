
#include "AppController.h"

AppController* AppController_new() { 
	// 새로운 AppController 객체를 동적으로 생성.
	AppController* _this;
	_this = NewObject(AppController);	
	return _this;	
}

void AppController_delete(AppController* _this) {
	//생성된 객체를 소멸.
	free(_this);	
}

void AppController_run(AppController* _this) {

	Boolean expressionIsAvailable, noErrorIsInEvaluation;	
	AppIO_out_startingMessage(); // 입력 시작 메시지 출력.
	_this->_postfix = Postfix_new(MAX_NUMBER_OF_TOKENS); // 새로운 Postfix를 동적으로 생성.
	expressionIsAvailable = AppIO_in_postfixExpression(_this->_expression);	//Postfix 수식 입력.
	while (expressionIsAvailable) {	
		Postfix_setExpression(_this->_postfix, _this->_expression);
		noErrorIsInEvaluation = Postfix_evaluate(_this->_postfix);
		if (!noErrorIsInEvaluation) { // 오류가 검출되었을 경우 메시지 출력.
			AppIO_out_errorInExpression();
		}
		else {
			// 오류 없이 정상적으로 입력되었으면 Postfix 수식 계산.
			AppIO_out_evaluatedValue(Postfix_evaluatedValue(_this->_postfix));
		}
		expressionIsAvailable = AppIO_in_postfixExpression(_this->_expression);
		// while문이 도는 동안 다시 Postfix 수식을 입력받음.
	}
	Postfix_delete(_this->_postfix);// Postfix 객체 삭제.
	AppIO_out_endingMessage();	
}
