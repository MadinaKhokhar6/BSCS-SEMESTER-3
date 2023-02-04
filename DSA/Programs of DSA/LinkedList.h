#include <iostream>
#include "Node.h" // including Node.h file
#include<stdlib.h>
using namespace std;
template<class T>
class LinkedList
{
private:
Node<T> *head; // head is variable whose data type is node
Node<T> *tail; // tail is variable whose data type is node
public:
LinkedList()
{
head=0;  //constructor { having same name as class}
tail=0;
}
 // here, we are declaring each functions to perform a particular task
   void addToHead(T element);
   void traversing();
   T removeFromHead();          //it will delete first Node
   void removeFromTail();
    void displayBill();
     void Remove(T element);
     void variabletype();
     Node<T>*getHead();
	 double searching(Node<T>* element);
	 Node<T>*setHead(Node<T>*u);
};

template<class T>
void LinkedList<T>::addToHead(T element){

Node<T> *ptr=new Node<T>(element);      
if(head==0 && tail==0)         // for the first time , it will work, as head and tail are equal to 0
{
head=ptr;
tail=ptr;
}
else             //only one element or >1 element            
{
ptr->setNext(head);
head=ptr;
}

}                            //addToHead

template<class T>
void LinkedList<T>::traversing(){
Node<T> *ptr=head;
while(ptr!=0) // till the end
{
       ptr->getInfo()->displayInfo();// getting the info of ptr and then display
ptr=ptr->getNext(); // set ptr to next
}
}                          //traversing

template<class T>
T LinkedList<T>::removeFromHead()  // fuction use to remove from head
{
if(head==0) // as list is empty and there is no value where we cannot delete any info
	   // so error will occur

{
cerr<<"nothing to delete"<<endl;
}
else if(head==tail) // in case there is only one element exist
{
T info=head->getInfo();
delete head;
head=0;
tail=0; // after deletig , we will set head and tail equal to 0
return info;
}
else                      //More than one element
{
Node<T> *temp=head;
head=head->getNext();
T info=temp->getInfo();
delete temp;
return info;
}}                        //Remove From Head

template<class T>
void LinkedList<T>::removeFromTail() {
    if(head==0){
        cerr<<"List cannot be empty";
    }
    else if(head==tail){
        head=0;
        tail=0;
    }
    else{
        Node<T>*ptr=head; // storing head in temp
        Node<T>*beforeadd;
        while(ptr->getNext()!=0&&ptr->getInfo()!=tail->getInfo()){
            beforeadd=ptr;
            ptr=ptr->getNext();
        }
        
        delete tail;
        tail=beforeadd;

    }
}                           //Remove From Tail

template<class T>
void LinkedList<T>::displayBill(){
    Node<T>*ptr=head; // setting ptr to head
    while(ptr!=0){ // till the end
cout<<ptr->getInfo()->getQuan()<<" ";
cout<<ptr->getInfo()->getId()<<" ";
cout<<endl;
ptr=ptr->getNext(); // setting ptr to next
    }
}//displayBill

template<class T>
void LinkedList<T>::Remove(T element){
if(head==0) //as list is empty and there is no value which we can delete  
	   // so error will occur

{
cerr<<"Nothing to delete"<<endl;
}
else if(head==tail && head->getInfo()->getId()==element->getId())
{
delete head;
head=tail=0;
}
else if(head->getInfo()->getId()==element->getId())
{
cout<<removeFromHead()<<endl;
cout<<"Value deleted";
}
else if(tail->getInfo()->getId()==element->getId())
{
removeFromTail(); // calling remove from head function
}
else
{
Node<T> *temp=head;
while(temp!=tail && temp->getNext()->getInfo()->getId()!=element->getId())
{
temp=temp->getNext();
}
if(temp==tail)
{
cerr<<"Element not found"<<endl;
}
else
{
Node<T> *ptr=temp->getNext();
temp->setNext(ptr->getNext());
delete ptr;
}
}
}                            //remove
template<class T>
double LinkedList<T>::searching(Node<T>* element)
{	
//double p=element->getInfo()->getQuan();
Node<T> *ptr=head;
while(ptr!=0)
{
if(ptr->getInfo()->getId()==element->getInfo()->getId())
{
string str=ptr->getInfo()->getPrice();
cout<<ptr->getInfo()->getId()<<"  ";
cout<<ptr->getInfo()->getName()<<"  ";
cout<<ptr->getInfo()->getDes()<<"  ";
double u=atof(str.c_str());
return p*u;
}
ptr=ptr->getNext();
}
cerr<<"item not found";
}
template <class T>
Node<T>* LinkedList<T>::getHead(){
return head;	
}
template <class T>
Node<T>* LinkedList<T>::setHead(Node<T>*u){
	head=u;
}
