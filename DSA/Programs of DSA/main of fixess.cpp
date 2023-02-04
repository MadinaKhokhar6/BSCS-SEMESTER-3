#include <iostream>
#include "LinkedStack.h"
#include <ctype.h>// for check its operater or digit
#include <stdlib.h>// for 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
// declaring functions
void numberConversion(int num);
void symbolBalancing(string text);
void postfixEvaluation(string exp);
string infixToPostfix(string exp);
string PostfixToinfix(string exp);
int prec(char op);
int main(int argc, char** argv) {
	
	LinkedStack<char>list1;
	list1.push('n');
	list1.push('u');
	list1.push('m');
	list1.push('l');
	list1.removeAndDisplayAll(); // calling removeAndDisplayAll() function
	cout<<endl;
	int opt;
do
{ 
// creating a menu

	cout<<"Press 1 for number conversion "<<endl;
	cout<<"Press 2 for check sequence of symbols "<<endl;
	cout<<"Press 3 to evaluate a postfix expression"<<endl;
    	cout<<"Press 4 to convert infix to postfix "<<endl;
    	cout<<"Press 5 to convert postfix to infix "<<endl;
	cout<<"Press 0 to exit "<<endl;
	cin>>opt;
	string text;
	switch (opt)
	{
		case 1:
			// call function for number conversion
			int num;
			cout<<"Provide number in decimal "<<endl;
			cin>>num; // getting a number for conversion
			cout<<endl;
			numberConversion(num); // calling a number conversion function
			break;
		case 2:
			
			cout<<"Provide sequence of symbols"<<endl;
			cin>>text; // getting a string of symbols
			symbolBalancing(text); // calling a symbol balancing funnction
			break;
	   case 3:
	        cout<<"Provide a postfix expression"<<endl;
	        cin>>text; // getting a expressionn for postfix expression
	        postfixEvaluation(text); // calling a postfixEvaluation
	   case 4:
	   	    cout<<"Provide an infix expression"<<endl;
	        cout<<"Conversion from infix to postfix "<<endl;
			cin>>text; // getting an infix expression
			infixToPostfix(text); // calling a infixToPostfix
			break;   
	   case 5:
	         cout<<"Provide an postfix expression"<<endl;
	        cout<<"Conversion from postfix to infix "<<endl;
			cin>>text;// getting an postfix expression
			PostfixToinfix(text);
			break;		  
		case 0:
		    exit(-1);	
	}//switch
}while(true); // do while

	return 0;
}

void numberConversion(int num) // number conversion function
{
	LinkedStack<int> stack;
	while(num>=1) //it should be greater than 0 
	{
		stack.push(num%2); // for remiander
		num=num/2; // for quotient
	}
	cout<<"conversion from decimal to binary";
	cout<<endl;
	stack.removeAndDisplayAll(); // calling remove and display function
	cout<<endl;
}// numbertConversion


void symbolBalancing(string text) // symbolBalancing function
{
	LinkedStack<char> stack;
	for(int i=0;i<text.length();i++)
	{
		if(text[i]=='('||text[i]=='['||text[i]=='{'||text[i]=='<')
		{ // If char is an opening symbol, push it on the stack
			stack.push(text[i]);
		}//2.1
		// If char is a closing symbol, then we will two situations
		else if(text[i]==')'||text[i]==']'||text[i]=='}'||text[i]=='>')
		{
			if(stack.isEmpty())//2.2.1
			{
				// If stack is empty, report an error ("Opening symbol missing”
				cout<<"opening symbol missing";
			}
			else//2.2.2
			{
				//If stack is non-empty, pop a char from stack and match it with input char
				char stackVal=stack.pop();
				if((text[i]==']'&& stackVal!='[')||(text[i]=='}'&& stackVal!='{')||(text[i]==')'&& stackVal!='(')||(text[i]=='>'&& stackVal!='<'))
				{ // If both characters do not match then report an error (“Symbol mismatch”)
					cout<<"Symbol mismatch"<<endl;
					
					return;
				}
			}
		}
	}
	
	if(!stack.isEmpty())
	{
		cout<<"IN6+valid sequence"<<endl;
	}
	else
	{
		cout<<"Valid Sequence \n";
	}
}

void postfixEvaluation(string exp)
{
	LinkedStack<double>s1;//Create an empty stack of type double

	for(int i=0;i<exp.length();i++)//Read input postfix expression char by char till the   end of input

	{
		if(isdigit(exp[i]))//operan 2.1
		{
		//	If char is an operand, convert it into its double equivalent 
			char operand=exp[i];
			double convertedOperand=atof(&operand);
			s1.push(convertedOperand); //then push it on the stack

		}
		else//operater
		{
		//	If char is an operator then pop two elements from the stack, 
			double op1=s1.pop();
			double op2=s1.pop();
			
			switch(exp[i])
			{
				// perfoming operation
				case '+':
					s1.push(op2+op1);
					break;
				case '-':
					s1.push(op2-op1);
					break;
				case '*':
					s1.push(op2*op1);
					break;
				case '/':
				    s1.push(op2/op1);	
				    break;
			}//switch end
		}//else
	}//for
	// pop the result and return
	cout<<"Answer is : "<<s1.pop()<<endl;
	
}//postfixEvaluation

int prec(char op) // set precedence
{
	if (op=='^')
	{
		return 3;
	}
	else if(op=='/'||op=='*')
	{
		return 2;	
	}
	else if(op=='+'||op=='-')
	{
		return 1;	
	}
}//prec
string infixToPostfix(string exp)
{
	LinkedStack<char>s1; //Create an empty stack of type char

	string output="";
	for(int i=0;i<exp.length();i++)//Read input expression char by char till the end of input

	{
		if(isdigit(exp[i]))// If operand then display it

		{
			output+=exp[i];
		}
		else if(exp[i]=='(')// If opening Parenthesis then push

		{
			s1.push(exp[i]);
		}
		else if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='/'||exp[i]=='^')//operater 2.3
		{
			if(s1.isEmpty())//empty then push
			{		
			   s1.push(exp[i]);	
			}
			else//nonempty then pop characters from stack and display them until we find an operator of lower precedence or an opening parenthesis or stack become empty.
			
			{
				while(!s1.isEmpty()&&s1.topValue()!='('&&prec(s1.topValue())>=prec(exp[i]))
				{
					output+=s1.pop();
				}//popping done
				s1.push(exp[i]);// When popping is done push the current operator on to the stack.
			}
		}
		else if(exp[i]==')')//closing symbol then Pop operators from stack and display them until 
		//we pop an opening parenthesis which will be popped but not displayed
		{
			while(s1.topValue()!='(')
			{
				output+=s1.pop();
			}
			//at top there is opening symbol
			s1.pop();
		}
	}//for 
	
	while(!s1.isEmpty()) // if stack is non empty
	{
		output+=s1.pop(); //, pop operators from stack and display them until the stack becomes empty.

	}
	
	cout<<"Postfix expression is : "<<output<<endl;
	return output;
}// end string infixToPostfix

string PostfixToinfix(string exp)
{
	LinkedStack<string>s1; //Create an empty stack of type string

	for(int i=0;i<exp.length();i++)//Read the input postfix expression char by char till the end of input

	{
		if(isdigit(exp[i]))//operand
		{
			string s(1,exp[i]);
			
			s1.push(s); // push char in stack
		}
		else//operater
		{
			string op1=s1.pop(); // pop two operands
            string op2=s1.pop();
			s1.push("("+op2+exp[i]+op1+")");// push the sub expression back on the stack
		}
	}//for
	cout<<"Infix expression is : "<<s1.topValue()<<endl;
	return s1.pop();
}
