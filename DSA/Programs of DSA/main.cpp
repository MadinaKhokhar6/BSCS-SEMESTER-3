#include <iostream>
#include "LinkedStack.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void numberConversion(int num);
void symbolBalancing(string text);
int main(int argc, char** argv) {
	
	LinkedStack<char>list1;
	list1.push('n');
	list1.push('u');
	list1.push('m');
	list1.push('l');
	list1.removeAndDisplayAll();
	cout<<endl;
	int opt;
do
{

	cout<<"Press 1 for number conversion "<<endl;
	cout<<"Press 2 for check sequence of symbols "<<endl;
	cout<<"Press 0 to exit "<<endl;
	cin>>opt;
	string text;
	switch (opt)
	{
		case 1:
			// call function for number conversion
			int num;
			cout<<"Provide number in decimal "<<endl;
			cin>>num;
			cout<<endl;
			numberConversion(num);
			break;
		case 2:
			
			cout<<"Provide swquence of symbols"<<endl;
			cin>>text;
			symbolBalancing(text);
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
		stack.push(num%2);
		num=num/2;
	}
	cout<<"conversion from decimal to binary";
	cout<<endl;
	stack.removeAndDisplayAll();
	cout<<endl;
}// numbertConversion


void symbolBalancing(string text)
{
	LinkedStack<char> stack;
	for(int i=0;i<text.length();i++)
	{
		if(text[i]=='('||text[i]=='['||text[i]=='{'||text[i]=='<')
		{
			stack.push(text[i]);
		}//2.1
		else if(text[i]==')'||text[i]==']'||text[i]=='}'||text[i]=='>')
		{
			if(stack.isEmpty())//2.2.1
			{
				cout<<"opening symbol missing";
			}
			else//2.2.2
			{
				char stackVal=stack.pop();
				if((text[i]==']'&& stackVal!='[')||(text[i]=='}'&& stackVal!='{')||(text[i]==')'&& stackVal!='(')||(text[i]=='>'&& stackVal!='<'))
				{
					cout<<"Symbol mismatch"<<endl;
					return;
				}
			}
		}
	}
	
	if(!stack.isEmpty())
	{
		cout<<"valid sequence"<<endl;
	}
}
