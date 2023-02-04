#include <iostream>
#include "LinkedStack.h" // including LinkedStack
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void numberConversion(int num); // declaring functions
void symbolBalancing(string text);
int main(int argc, char** argv) {

	LinkedStack<char>list1;
	list1.push('n');
	list1.push('u');
	list1.push('m');
	list1.push('l');
	list1.removeAndDisplayAll(); // calling function
	cout<<endl;
	int opt;
do
{  // menu

	cout<<"Press 1 for number conversion "<<endl;
	cout<<"Press 2 for check sequence of symbols "<<endl;
	cout<<"Press 0 to exit "<<endl;
	cin>>opt;
	string text;
	switch (opt) // using switch
	{
		case 1:
			// call function for number conversion
			int num;
			cout<<"Provide number in decimal "<<endl;
			cin>>num; // getting a number for conversion
			cout<<endl;
			numberConversion(num); // calling  a number conversion function
			break;
		case 2:

			cout<<"Provide sequence of symbols"<<endl;
			cin>>text;  // getting a string of symbols
			symbolBalancing(text); // calling a symbol balancing funnction
			break;
		case 0:
		    exit(-1);
	}
}while(true);

	return 0;
}

void numberConversion(int num) // number conversion function
{
	LinkedStack<int> stack;
	while(num>=1) //it should be greater than 0  as 0 is  binary
	{
		stack.push(num%2);// for  remiander
		num=num/2; // for quotient
	}
	cout<<"conversion from decimal to binary";
	cout<<endl;
	stack.removeAndDisplayAll(); // calling  remove  and display function
	cout<<endl;
}// numbertConversion


void symbolBalancing(string text) // symbolBalancing function
{
	LinkedStack<char> stack;
	for(int i=0;i<text.length();i++)
	{
		if(text[i]=='('||text[i]=='['||text[i]=='{'||text[i]=='<')
		{  // If char is an opening symbol, push it on the stack

			stack.push(text[i]);
		}//2.1

		// If char is a closing symbol, then we will two situations
		else if(text[i]==')'||text[i]==']'||text[i]=='}'||text[i]=='>')
		{
			// If stack is empty, report an error ("Opening symbol missing")
			if(stack.isEmpty())//2.2.1
			{
				cout<<"opening symbol missing";
			}
			else//2.2.2
			{
				//If stack is non-empty, pop a char from stack and match it with input char.
				
				char stackVal=stack.pop();
				
				if((text[i]==']'&& stackVal!='[')||(text[i]=='}'&& stackVal!='{')||(text[i]==')'&& stackVal!='(')||(text[i]=='>'&& stackVal!='<'))
				{
					// If both characters do not match then report an error ("Symbol mismatch")
					cout<<"Symbol mismatch"<<endl;
					return;
				}
			}
		}
	}

	if(!stack.isEmpty()) // is stack is not empty
	{
		cout<<"valid sequence"<<endl;
	}
}






