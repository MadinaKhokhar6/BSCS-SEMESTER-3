#include<iostream>
using namespace std;

template<class T> // Templates actually increase flexibility, they're easy
// to update, and they provide consistency across the project
class TWNode
{
	private:
		TWNode<T> *prev; // variable use to store address  of next node,that's why its data type
		// is node
		T info;  //  variable name use to store information
		TWNode<T> *next; // variable use to store address  of next node,that's why its data type
		// is node
	
	public:
		TWNode(T i=0,TWNode<T> *p=0,TWNode<T> *n=0):info(i),next(n),prev(p)
		{
			 // constructor { having same name as class}
		}
		
		void setInfo(T i);  // making setter and getter for info
		T getInfo();
		void setNext(TWNode<T> *n); // making setter and getter for NEXT node
		TWNode<T>* getNext();
		void setPrev(TWNode<T> *p);  // making setter and getter for PREV node
		TWNode<T>* getPrev();
};//EOC

template<class T>
void TWNode<T>::setInfo(T i)  // setting our info
{
	info=i;
}

template<class T>
void TWNode<T>::setNext(TWNode<T> *n) // setting our Next
{
	next=n;
}

template<class T>
T TWNode<T>::getInfo() // getting  our info
{
	return info;
}

template<class T>
TWNode<T>* TWNode<T>::getNext() // getting  our NEXT
{
	return next;
}


template<class T>
TWNode<T>* TWNode<T>::getPrev() // getting  our PREV
{
	return prev;
}

template<class T>
void TWNode<T>::setPrev(TWNode<T> *p)   // setting our PREV
{
	prev=p;
}
