#include<iostream>
#include "Node.h" // To include node.h file
using namespace std;
template<class T> // Templates actually 
//increase flexibility, they're easy  to update, and they provide consistency
class LinkedStack
{
     private:
	 Node<T> *top; // top is declared which is the fudamental characteristics of linked stack 
	 public:
	 LinkedStack() // constructor
	 {
	      top=0;  // setting top to 0	
	 }	
	 void push(T element); //add to head
	 T pop(); // remove from head
	 bool isEmpty();  
	 T topValue(); // tp access top value
	 void removeAndDisplayAll();  // to remove and display
};

template<class T>
void LinkedStack<T>::push(T element)
{
  	
	Node<T> *ptr=new Node<T>(element);// creating a node
	//info=5 & next=0
	
	if(top==0)// if list is empty
	{
		top=ptr; // then top will be set to ptr
	
	}
	else //only one element or >1 element
	{
		ptr->setNext(top); // Increment top //next of 9 is 23
		top=ptr;//head will now poT Node<T> with value 9
	}
		
}//push
template<class T>
T LinkedStack<T>::pop() // to pop en elemnet
{
	if(top==0) // is stack is empty
	{
		cerr<<"nothing to delete"<<endl; // then error occur
	}
	else if(top->getNext()==0) // if only one element exist
	{
		T info=top->getInfo(); //storing value of top info in info variable 
		delete top; // deleting value at tho top 
		top=0;
	
		return info;
	}
	else//more than one element
	{
		Node<T> *temp=top; // storing top in temp 
		top=top->getNext(); // increment top 
		T info=temp->getInfo();
		delete temp;
		return info; // it will return info which is being deleted
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
	return top->getInfo(); // getting value at the top and then return
} //topValue

template<class T>
void LinkedStack<T>::removeAndDisplayAll()
{
	while(top!=0) // // until stack become empty and passes through all nodes
	{
		cout<<pop()<<" ";
		//cout<<endl;
	}
}//removeAndDisplayAll
