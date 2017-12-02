#include<iostream>
#include<stack> // STL Library
#include<string>
using namespace std;

bool Pairing(char open, char close)
{
	if(open == '(' && close == ')')
		return true;
	else if(open == '[' && close == ']')
		return true;
	else if(open == '{' && close == '}')
		return true;
	return false;
}

string IsOpen(char c){
	if(c == '(' || c == '{' || c == '[')
		return "open";
	else if (c == ')' || c == '}' || c == ']')
		return "closed";
	else return "other";

}

bool IsBalanced(string exp)
{
	stack<char> mystack;
	for(int i =0; i<exp.length(); i++)
	{
		if(IsOpen(exp[i]) == "other")
		{
			continue;
		}
		else if(IsOpen(exp[i])=="open")
			mystack.push(exp[i]);
		else if(IsOpen(exp[i]) == "closed")
		{
			if(mystack.empty() || !Pairing(mystack.top(),exp[i]))
				return false;
			else
				mystack.pop();
		}


	}
	if(mystack.empty()) return true;
	else return false;
}

int main()
{
	string exp;
	cin>>exp;

	cout << (IsBalanced(exp)? "Balanced":"Not Balanced") << endl;
}