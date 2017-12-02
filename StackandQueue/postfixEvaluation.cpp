#include <iostream>
#include <stack> // STL library
#include <string>

using namespace std;

string get_token(char token){
	if(token == '+' || token == '-' || token == '*' || token == '/' || token == '%')
		return "operator";
	else if(token >= '0' && token <= '9')
		return "operand";
}
stack<int> mystack;
void eval(string exp){
	char symbol;
	int op1, op2;
	for(int i = 0; i<exp.length(); i++){
		if(get_token(exp[i]) == "operator"){
			op2 = mystack.top();
			mystack.pop();
			op1 = mystack.top();
			mystack.pop();
			switch(exp[i]) {
				case '+': mystack.push(op1+op2); break;
				case '-': mystack.push(op1-op2); break;
				case '*': mystack.push(op1*op2); break;
				case '/': mystack.push(op1/op2); break;
				case '%': mystack.push(op1%op2);
			}
		}
		else if(get_token(exp[i]) == "operand"){
			mystack.push(exp[i] - '0');

		}
	}
}

int main(){
	eval("23*54*+9-");
	cout << "hi " << mystack.top();
	return 1;
}