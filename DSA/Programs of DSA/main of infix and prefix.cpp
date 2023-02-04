#include <iostream>
#include "LinkedStack.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void numberConversion(int num);
void symbolBalancing(string text);
int main(int argc, char** argv) {
	
	LinkedStack<char>list1;
	list1.push('n');//Inserting an element to list1
	list1.push('u'); //Inserting an element to list1
	list1.push('m'); //Inserting an element to list1
	list1.push('l'); //Inserting an element to list1
	list1.removeAndDisplayAll();//this will remove all and display them
	cout<<endl;
	int opt;
do
{

	cout<<"\nPress 1 for number conversion "<<endl;
	cout<<"Press 2 for check sequence of symbols "<<endl;
	cout<<"Press 3 to evaluate a postfix expression"<<endl;
    	cout<<"Press 4 to convert infix to postfix "<<endl;
    	cout<<"Press 5 to convert postfix to infix "<<endl;
	cout<<"Press 6 to convert infix to prefix"<<endl;
	cout<<"Press 7 to convert prefix to infix "<<endl;
	cout<<"Press 0 to exit "<<endl;
	cin>>opt;
	string text;
	switch (opt)
	{
		case 1:
			// call function for number conversion
			int num;
			cout<<"Provide number in decimal "<<endl;//ask the user for a number
			cin>>num;//Insert that number in "num"
			cout<<endl;
			numberConversion(num);//calling the function of numberconversion
			break;
	    case 2:
	cout<<"Provide sequence of symbols"<<endl;//ask the user to provide the sequence of symbols
			cin>>text;//get the symbols in text variable 
			symbolBalancing(text);//call the function of symbolBalancing
			break;
case 3:
	        cout<<"Provide a postfix expression"<<endl;
	        cin>>text;
	        postfixEvaluation(text);
 	        break;
	   case 4:
	   	    cout<<"Provide an infix expression"<<endl;
	        cout<<"Conversion from infix to postfix "<<endl;
			cin>>text;
			infixToPostfix(text);
			break;   
	   case 5:
	        cout<<"Provide an postfix expression"<<endl;
	        cout<<"Conversion from postfix to infix "<<endl;
			cin>>text;
			PostfixToinfix(text);
			break;		  
       case 6:
       	    cout<<"Conversion from infix to prefix "<<endl;
       	    cout<<"Provide an infix expression"<<endl;
       	    cin>>text;
			infixToPrefix(text);
       	    break;
       case 7:
	          cout<<"Provide an prefix expression"<<endl;
	        cout<<"Conversion from prefix to infix "<<endl;
			cin>>text;
       	    PrefixToinfix(text);
       	    break;	
case 0:
		    exit(-1);	
	}
}while(true);

	return 0;
}

void numberConversion(int num)
{
	LinkedStack<int> stack;
	while(num>=1)
	{
		stack.push(num%2);//inserting the remainder of number in stack
		num=num/2;//number becomes half
	}
	cout<<"conversion from decimal to binary";
	cout<<endl;
	stack.removeAndDisplayAll();//it will remove all elements and display them all
	cout<<endl;
}// numbertConversion


void symbolBalancing(string text)
{
	LinkedStack<char> stack;
	for(int i=0;i<text.length();i++)//loop will run un till the length
	{
		if(text[i]=='('||text[i]=='['||text[i]=='{'||text[i]=='<')//condition that all opening brakets gone to stack.
		{
			stack.push(text[i]);
		}//2.1
		else if(text[i]==')'||text[i]==']'||text[i]=='}'||text[i]=='>')//else if brakets are closed then match them with the opening brakets in stack.
		{
			if(stack.isEmpty())//2.2.1
			{
				cout<<"opening symbol missing";
			}
			else//2.2.2
			{
				char stackVal=stack.pop();//delete an  element and store it in stackval
				if((text[i]==']'&& stackVal!='[')||(text[i]=='}'&& stackVal!='{')||(text[i]==')'&& stackVal!='(')||(text[i]=='>'&& stackVal!='<'))//matching the closing brakets with the opening brakets in stack.
				{
					cout<<"Symbol mismatch"<<endl;
					return;
				}
			}
		}
	}
	if(!stack.isEmpty()) // condition to check weather the stack is empty or not.
	{
		cout<<"valid sequence"<<endl;
	}
	else // if stack is not empty
	{
		cout<<"Valid Sequence \n";
	}
}//end of synbol sequence


void postfixEvaluation(string exp) // function definition
{
	LinkedStack<double>s1;//rule 1
	for(int i=0;i<exp.length();i++)//rule 2
	{
		if(isdigit(exp[i]))//operand 2.1
		{
			char operand=exp[i];// storing expression char in a variable
			double convertedOperand=atof(&operand);// convert char into double by using atof built in function
			s1.push(convertedOperand);// push convertedOperand to stack
		}
		else//operater
		{
			double op1=s1.pop(); //store value in variable op1 that is pop
			double op2=s1.pop(); //store value in variable op2 that is pop
			
			switch(exp[i]) // switch statement for checking operater
			{
				case '+':
					s1.push(op2+op1); // adding op1 and op2
					break;
				case '-':
					s1.push(op2-op1); //subtracting op1 and op2
					break;
				case '*':
					s1.push(op2*op1); // multiplication of op1 and op2
					break;
				case '/':
				    s1.push(op2/op1); // division of op1 and op2	
				    break;
			}//switch end
		}//else
	}//for
	
	cout<<"Answer is : "<<s1.pop()<<endl;// display the result
	
}//postfixEvaluation

int prec(char op) //function for evaluating the precedences of operaters
{
	if (op=='^') //if statement
	{
		return 3;
	}
	else if(op=='/'||op=='*')  //else if statement
	{
		return 2;	
	}
	else if(op=='+'||op=='-') // else if statement
	{
		return 1;	
	}
}//prec
string infixToPostfix(string exp) //function for infixToPostfix conversion
{
	LinkedStack<char>s1; // declare empty stack of type char
	string output=""; // variable of string type
	for(int i=0;i<exp.length();i++)//rule :2
	{
		if(isdigit(exp[i]))//operand
		{
			output+=exp[i]; // loading exp[i] in output variable
		}
		else if(exp[i]=='(')//opening symbol
		{
			s1.push(exp[i]); // push exp[i] value on stack
		}
		else if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='/'||exp[i]=='^')//operater 2.3
		{
			if(s1.isEmpty())// if stack is empty
			{		
			   s1.push(exp[i]);//  push exp[i] value on stack	
			}
			else//if stack is nonempty
			{
				while(!s1.isEmpty()&&s1.topValue()!='('&&prec(s1.topValue())>=prec(exp[i])) //if stack is not empty and stack's top value not is equal to '(' closing paranthesis and precedence of stack's top is greater or equal to the precedence of exp[i] value than this while loop's condition becomes true 
				{
					output+=s1.pop(); // storing poped value in output variable 
				}//popping done
				s1.push(exp[i]); // push exp[i] value on stack
			}
		}
		else if(exp[i]==')')//closing symbol rule :2.4
		{
			while(s1.topValue()!='(') // if stack's top value not is equal to opening paranthesis '(' 
			{
				output+=s1.pop(); // storing poped value in output variable  
			}
			//at top there is opening symbol
			s1.pop(); // pop opening paranthesis but not load/store in stack
		}
	}//for end
	
	while(!s1.isEmpty()) //if stack is not empty
	{
		output+=s1.pop(); // storing poped value in output variable  
	}
	
	cout<<"Postfix expression is : "<<output<<endl; //print 'Postfix expression'
    return output; //return 'Postfix expression'
}// end string infixToPostfix

string PostfixToinfix(string exp) //function for PostfixToinfix conversion
{
	LinkedStack<string>s1; // declare empty stack of type string
	for(int i=0;i<exp.length();i++) // exp.length() means till the end of expression
	{
		if(isdigit(exp[i]))//operand
		{
			string s(1,exp[i]); // converting from char into string because stack is string type
			s1.push(s); // push in stack
		}
		else//operater
		{
			string op1=s1.pop(); // storing pop element in op1
            string op2=s1.pop();  // storing pop element in op2
			s1.push("("+op2+exp[i]+op1+")"); // inserting operater and push this sub-expression back in stack 
		}
	}//for
	cout<<"Infix expression is : "<<s1.topValue()<<endl; // print final Infix expression
	return s1.pop(); // pop final expression and return
}

string infixToPrefix(string exp) //function for infixToPrefix conversion
{
	LinkedStack<char>s1; // declare empty stack of type char
	string output="";  // variable of string type
	reverse(exp.begin(), exp.end()); // use buit in function for reverse the expression
	for(int i=0;i<exp.length();i++) //rule :2
	{
		if(isdigit(exp[i]))//operand
		{
			output+=exp[i]; // loading exp[i] in output variable
		}
		else if(exp[i]==')')  //closing symbol
		{
			s1.push(exp[i]);  // push exp[i] value on stack
		}
		else if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='/'||exp[i]=='^')//operater 2.3
		{
			if(s1.isEmpty())//empty
			{		
			   s1.push(exp[i]);	  // push exp[i] value on stack
			}
			else//nonempty
			{
				while(!s1.isEmpty()&&s1.topValue()!=')'&&prec(s1.topValue())>prec(exp[i])) // while loop execute if stack is not empty and stack's topValue not is equal to closing parathesis ')' and stack's topValue precedence > precedence of exp[i] value
				{
					output+=s1.pop();  // storing poped value in output variable 
				}//popping done
				s1.push(exp[i]); // push exp[i] value on stack
			}
		}
		else if(exp[i]=='(')//opening symbol 2.4
		{
			while(s1.topValue()!=')') // if stack's top value not is equal to opening paranthesis ')'
			{
				output+=s1.pop();  // storing poped value in output variable 
			}
			//at top there is opening symbol
			s1.pop(); // pop opening paranthesis but not load/store in stack
		}
	}//for end 
	
	while(!s1.isEmpty())  //if stack is not empty
	{
		output+=s1.pop(); // storing poped value in output variable  
	}
	
	reverse(output.begin(), output.end()); // use buit in function for reverse the expression
	cout<<"Prefix expression is : "<<output<<endl; //print 'Prefix expression'
	return output; //return 'Postfix expression'
	}// end string infixToPrefix
	
string PrefixToinfix(string exp) //function for PrefixToinfix conversion
{
	LinkedStack<string>s1; // declare empty stack of type string
	reverse(exp.begin(), exp.end()); // use buit in function for reverse the expression
	for(int i=0;i<exp.length();i++)  // exp.length() means till the end of expression
	{
		if(isdigit(exp[i]))//operand
		{
			string s(1,exp[i]);	 // converting from char into string because stack is string type
			s1.push(s);  // push in stack
		}
		else//operater
		{
			string op1=s1.pop(); // storing pop element in op1
            string op2=s1.pop(); // storing pop element in op2
			s1.push(")"+op2+exp[i]+op1+"("); // inserting operater and push this sub-expression back in stack
		}
	}//for end
	
	string output=s1.topValue(); // storing final expression in an string type variable of name output
	reverse(output.begin(), output.end()); // use buit in function for reverse the expression
	cout<<"Infix expression is : "<<output<<endl; // print final Infix expression
	return s1.pop(); // pop final expression and return
} // end of  function PrefixToinfix conversion

