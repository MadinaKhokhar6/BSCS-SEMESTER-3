#include<iostream>
#include "Node.h"
using namespace std;
template<class T>	
class LinkedStack
{
     private:
	 Node<T> *top; //   top is declared which is the fudamental characteristics of linked stack
	 public:
	 LinkedStack()  // constructor
	 {
	      top=0; // setting top to zero
	 }
	 // declaring functions
	 void push(T element); //add to head
	 T pop(); // remove from head
	 bool isEmpty(); //  is empty
	 T topValue(); // to access top value
	 void removeAndDisplayAll(); //to remove  and  diplay
};

template<class T>
void LinkedStack<T>::push(T element)   // to push  element
{

	Node<T> *ptr=new Node<T>(element); // creating a node
	//info=5 & next=0

	if(top==0)//list is empty
	{
		top=ptr;

	}
	else //only one element or >1 element
	{
		ptr->setNext(top); // Increment top     //next of 9 is 23
		top=ptr; // Insert value at top index

		//head will now poT Node<T> with value 9
	}

}//push
template<class T>
T LinkedStack<T>::pop() // to pop en elemnet
{
	if(top==0)   // is stack is empty
	{
		cerr<<"nothing to delete"<<endl;
	}
	else if(top->getNext()==0)   // if only one element exist
	{
		T info=top->getInfo(); //storing value of  top info in info variable
		delete top; // deleting value at tho top
		top=0;

		return info; // returning value of info( deleted value)
	}
	else//more than one element
	{
		Node<T> *temp=top;  // storing  top in temp
		top=top->getNext(); // increment top
		T info=temp->getInfo();
		delete temp;
		return info;
	}
}//pop
template<class T>
bool LinkedStack<T>::isEmpty()
{
	return top==0;
}//isEmpty

template<class T>
T LinkedStack<T>::topValue()
{
	return top->getInfo(); // getting value  at the top and then return
} //topValue

template<class T>
void LinkedStack<T>::removeAndDisplayAll()
{
	while(top!=0)  // until stack become  empty
	{
		cout<<pop()<<" "; // calling pop function
		//cout<<endl;
	}
}//removeAndDisplayAll



