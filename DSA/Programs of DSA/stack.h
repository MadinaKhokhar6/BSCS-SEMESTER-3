#include<iostream>
using namespace std;
class stack
{
 private:
       int top;
     int arr[5];
 public:
       stack()
       {
	   top =-1;
 	 for(int i=0;i<5;i++)
 	 {
 	 	arr[i]=0;
	  }
}
	 
	 bool isEmpty()
	 {
	 	if (top ==-1)
	 	return true;
	 	else
	 	 return false;
		 
		 }	 // endofis empty
		 
		 bool isFull();
		 if(top==5-1)
		 return true;
		 
		 else{
		 	return false;
		 }
		void push (int val)
		if(isFull())
{  cout<<"overflow"<<endl;
		 }
		 else
		 { top++
		 arr[top]=val;
				  }
	int pop()
	{ if(is empty())
		cout<<"overflow.."<<endl;
		return 0; 	 }
		else
		{ int popValue == arr[top]
		arr[top]==0;
		top--;
 	
			}	
			int count()
			{
				return(top+1);
				 }
	int peek(int pos)
	{
	 if(is empty())
		cout<<"overflow.."<<endl;
		return 0; 	 }
		else
		{
			return(arr[pos]); 
				}	
		 }	 
	 void replace(int pos,int val)
	 {
	 if(is empty())
		cout<<"overflow.."<<endl;
		return 0; 	 }
		else
		{ 
		arr[pos]= val;
		cout<<"item replace at the location"<<pos<<"is"<<arr[pos]<<endl;
		}
	 }
	 void display()
	 {
	 	cout<<"Elements in the stack are"<<endl;
	 	for(int i =4,i<=0,i--)
	 	cout<<arr[i]<<endl;
	 }
	 
	 
};
