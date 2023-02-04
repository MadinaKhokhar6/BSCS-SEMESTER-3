#include <iostream>
#include "TWNode.h"  // here we are including our node class
using namespace std;
template<class T>   // Templates actually increase flexibility, they're easy
// to update, and they provide consistency across the project
class TWLinkedList 
{
	private:
		TWNode<T> *head; // head is variable whose data type is node
		TWNode<T> *tail;  // tail is variable whose data type is node
	public:
		TWLinkedList() // constructor { having same name as class}
		{
			head=0;   // tail and head  as initially our slot is empty
			tail=0;
		}
		// here, we are calling each functions to perform a particular task
		void traverseBackward();
		void traversing();
		void addToHead(T element);
		void addToTail(T element);
		void addAfter(T existing, T element);
		TWNode<T>* searching(T element);
		void addBefore(T existing, T element);
		/*~LinkedList();
	    
	    
	    
	    
	    
	    T removeFromHead();//it will delete first Node<T> and will return of deleted info
	    //T removeFromTail();
	    void remove(T element);//will deleted Node<T> having provided info
	    void removeAll();*/
};

template<class T>
void TWLinkedList<T>::traverseBackward()
{
	TWNode<T> *ptr=tail;  // storing tail in ptr
	while(ptr!=0)
	{
		cout<<ptr->getInfo()<<" "; // here we will print our info starting from tail and 
		// we will wen at head
		ptr=ptr->getPrev();
	}
}//traverseBackward()

template<class T>
void TWLinkedList<T>::traversing()
{
	TWNode<T> *ptr=head; // storing head in ptr
	while(ptr!=0) // here , we will move towards each value one by one untill our head become
	// zero and will print our values
	{
		cout<<ptr->getInfo()<<" ";
		ptr=ptr->getNext(); // moving our ptr to next 
	}
}//traversing

template<class T>
void TWLinkedList<T>::addToHead(T element)//element=9
{
	/*Node<T> *ptr=new Node<T>();//info=0 and next=0
	ptr->setInfo(element);//info=9
	ptr->setNext(0);//next=0*/
	
	TWNode<T> *ptr=new TWNode<T>(element);//info=5 & next=0
	// CREATIG A NEW NODE
	
	if(head==0 && tail==0)//list is empty
	{
		head=ptr;  // if there is no element in list then our ptr is head and also tail
		tail=ptr;
	}
	else //only one element or >1 element
	{
		ptr->setNext(head);//next of 9 is 23
		head->setPrev(ptr); // setting our addresses
		head=ptr;//head will now poT Node<T> with value 9
	}
	
}//addToHead

template<class T>
void TWLinkedList<T>::addToTail(T element)
{
	TWNode<T> *ptr=new TWNode<T>(element);
	
	if(head==0 && tail==0)//list is empty
	{
		head=ptr;  // if there is no element in list then our ptr is head and also tail
		tail=ptr;
	}
	else //only one element or >1 element
	{
		tail->setNext(ptr); // setting addresses
		ptr->setPrev(tail);
		tail=ptr; // set ptr as tail
	}
}//addToTail

template<class T>
void TWLinkedList<T>::addAfter(T existing, T element)
{
	if(head==0)//list is empty
	{
		cerr<<"List is empty therefore, existing cannot exist"<<endl;
	}
	else if(existing==tail->getInfo())//only 1 element & existing is at that single element || if >1 element and existing gets match with last node
	{
		/*Node<T> *ptr=new Node<T>(element);
		tail->setNext(ptr);
		tail=ptr;*/
		addToTail(element);//it will always execute else part of this function because list is non empty
	}
	else//list is non empty and also existing does not exist at tail
	{
		//it this else is execute it means that existing is somewhere before tail or it does not exist at all
		TWNode<T> *loc=searching(existing);//it may return 0 (if existing not found) or it may return hexdecimal address if existing found
		if(loc==0)
		{
			cerr<<"Existing not found"<<endl; // it means our element has not found 
		}
		else//existing found somewhere before tail
		{
			TWNode<T> *ptr=new TWNode<T>(element); // creating a new node
			ptr->setPrev(loc);
			ptr->setNext(loc->getNext()); // here we will set our addresses accurately
			loc->setNext(ptr);
			ptr->getNext()->setPrev(ptr);
			
		}
		
	}
}

template<class T>
TWNode<T>* TWLinkedList<T>::searching(T element)//100
{
	TWNode<T> *loc=0;
	
	TWNode<T> *ptr=head; // storing head in a ptr
	while(ptr!=0)  // to run at the at the end of the list
	{
		if(ptr->getInfo()==element) // if element is founded
		{
			loc=ptr;
			return loc;//whenever it will be executed it will return true hexadecimal loc instead 0
		}
		ptr=ptr->getNext();//we need to take ptr to its next if element does not match
	}
	return loc;//whenever it will be executed it will always return 0
}

template<class T>
void TWLinkedList<T>::addBefore(T existing, T element)
{
	if(head==0)//empty
	{
		cerr<<"Existing cannot be found"<<endl;
		// if there is no element in list hence there is nothing to found so error will occur
	}
	else if(head->getInfo()==existing)//existing is on head node
	{
		addToHead(element); // if element is at the head
	}
	else//existing can exist after head node
	{
		TWNode<T> *loc=searching(existing);
		if(loc==0)
		{
			cerr<<"Existing not found"<<endl; // element does not exist
		}
		else
		{
			TWNode<T> *ptr=new TWNode<T>(element); // creating a new node
			loc->getPrev()->setNext(ptr);
			ptr->setPrev(loc->getPrev());  // here we will set our addresses
			loc->setPrev(ptr);
			ptr->setNext(loc);
		}
	}
	
}//addBefore

