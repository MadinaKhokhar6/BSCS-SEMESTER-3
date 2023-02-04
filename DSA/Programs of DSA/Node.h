#include<iostream>
using namespace std;
template<class T>  // Templates actually 
//increase flexibility, they're easy  to update, and they provide consistency
class Node
{
private:
T info;  //  variable name use to store information
Node<T> *next; // variable use to store address of next node,that's why its data type

public:
Node(T i=0,Node<T> *n=0):info(i),next(n)
{
	// constructor { having
}

void setInfo(T i); // using setter and getter
T getInfo();
void setNext(Node<T> *n);// using setter and getter
Node<T>* getNext();
};//EOC

template<class T>
void Node<T>::setInfo(T i)
{
info=i; // setting our info
}

template<class T>
void Node<T>::setNext(Node<T> *n)
{
next=n; // setting our next
}

template<class T>
T Node<T>::getInfo() // getting our info
{
return info;
}

template<class T>
Node<T>* Node<T>::getNext() // getting our next
{
return next;
}

