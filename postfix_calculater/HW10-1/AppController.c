
#include "AppController.h"

AppController* AppController_new() { 
	// ���ο� AppController ��ü�� �������� ����.
	AppController* _this;
	_this = NewObject(AppController);	
	return _this;	
}

void AppController_delete(AppController* _this) {
	//������ ��ü�� �Ҹ�.
	free(_this);	
}

void AppController_run(AppController* _this) {

	Boolean expressionIsAvailable, noErrorIsInEvaluation;	
	AppIO_out_startingMessage(); // �Է� ���� �޽��� ���.
	_this->_postfix = Postfix_new(MAX_NUMBER_OF_TOKENS); // ���ο� Postfix�� �������� ����.
	expressionIsAvailable = AppIO_in_postfixExpression(_this->_expression);	//Postfix ���� �Է�.
	while (expressionIsAvailable) {	
		Postfix_setExpression(_this->_postfix, _this->_expression);
		noErrorIsInEvaluation = Postfix_evaluate(_this->_postfix);
		if (!noErrorIsInEvaluation) { // ������ ����Ǿ��� ��� �޽��� ���.
			AppIO_out_errorInExpression();
		}
		else {
			// ���� ���� ���������� �ԷµǾ����� Postfix ���� ���.
			AppIO_out_evaluatedValue(Postfix_evaluatedValue(_this->_postfix));
		}
		expressionIsAvailable = AppIO_in_postfixExpression(_this->_expression);
		// while���� ���� ���� �ٽ� Postfix ������ �Է¹���.
	}
	Postfix_delete(_this->_postfix);// Postfix ��ü ����.
	AppIO_out_endingMessage();	
}
