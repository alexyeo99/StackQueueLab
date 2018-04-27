/*
Alex Yeo
For CMSC21 Lab
Have fun!
*/
#include <iostream>
#include <string.h>
#include <stack>

using namespace std;

string infixToPostfixConverter(string infix);
bool higherPrecedence(char input, char compare);

int main(){
	string test = "1+2+3";
	cin >> test;
	cout << infixToPostfixConverter(test) << endl;
	return 0;
}

string infixToPostfixConverter(string infix){
	string output = "";
	stack<char> pfix;
	//following the ppt:
	//push ( to stack:
	pfix.push('(');
	//append ) to end of infix:
	infix = infix + ")";
	//
	int i=0;
	while(!pfix.empty()){
		//iterate trough input string
		//[48,57] is digit
	
		//check if digit:
		if(infix[i] >= 48 && infix[i] <=57){
			//append to postfix:
			output = output + infix[i];
		}
		//if left parenthesis, push to stack
		if(infix[i] == '('){
			pfix.push('(');
		}
		//if operator:
		if(infix[i] == '+' || infix[i] == '-' || infix[i] == '/' || infix[i] == '*'){
			while(higherPrecedence(infix[i],pfix.top())){
				cout << "higher precedence met." << endl;
				output = output + pfix.top();
				pfix.pop();
				
			}
			pfix.push(infix[i]);
		}
		if(infix[i] == ')'){
			while(pfix.top()!='('){
				output = output + pfix.top();
				pfix.pop();
			}
			pfix.pop();
		}
		i++;
	}
	
	return output;
}

bool higherPrecedence(char input, char compare){
	if(input == '+' || input == '-'){
		if(compare == '*' || compare == '/'){
			return false;
		}
	}
	if(input == '*' || input == '/'){
		if(compare == '+' || compare == '-'){
			return true;
		}
	}
	return false;
}