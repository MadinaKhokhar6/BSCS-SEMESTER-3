#include <iostream>
#include "LinkedList.h" // including linkedlist file
#include "items.h"   // including item file
#include<fstream> // for file handling
#include<string> // to handle string
using namespace std;
string strings[4];
int len(string str){  
    int length = 0;  
    for (int i = 0; str[i] != '\0'; i++)  
    {  
        length++;  
         
    }  
    return length;    
}  
void split (string str, char seperator)  {  
    int currIndex = 0, i = 0;  
    int startIndex = 0, endIndex = 0;  
    while (i <= len(str))  // less than  or equal tolength of string
    {  
        if (str[i] == seperator || i == len(str))  
        {  
            endIndex = i;  
            string subStr = "";  
            subStr.append(str, startIndex, endIndex - startIndex);  
            strings[currIndex] = subStr;  
            currIndex += 1;  
            startIndex = endIndex + 1;  
        }  
        i++;  
        }    
}  

int main() {
LinkedList<items*> item;// object
ifstream obj;
obj.open("Downloads"); // giving path
if(!obj){ // in case file does not exist
cout<<"File dont exist";
return 1;
}
else{
string str;
while(getline(obj,str)){
split(str,'_');
items *p1=new items(strings[0],strings[1],strings[2],strings[3]);
item.addToHead(p1);  // calling add to head function
}
//displaying all the data
cout<<"Following are the grocery items"<<endl;
item.traversing(); // displaying items
LinkedList <items*> cart;
  do{
int opt;
    cout<<"Press 1 to enter an item in cart"<<endl;
    cout<<"Press 2 to delete an item"<<endl;
    cout<<"press 3 to display all the elements"<<endl;
    cout<<"Press 4 to print bill"<<endl;
    cout<<"enter the option ";
    cin>>opt;
    string id;
    double quantity,totalprice;
  items *p=new items();
    switch(opt){
  
	case 0:
		while(cart.getHead()!=0)
		{
			double price;
			price=item.searching(cart.getHead());
			//cout<<cart.getHead()->getInfo()->getQuan()<<"  ";
			cout<<price<<endl;
			cart.setHead(cart.getHead()->getNext());
			totalprice+=price;
		}
		cout<<"total Price:   "<<totalprice;
    exit(-1);
    break;
    
    case 1:
    	cout<<"enter the Id: ";
        cin>>id;
        cout<<"Enter quantity: ";
        cin>>quantity;
        p->setId(id);
        p->setQuan(quantity);
        cart.addToHead(p);
    	break;
    
   	case 2:
   		cout<<"Enter the Id: ";
   		cin>>id;
   		p->setId(id);
   		cart.Remove(p);
   		break;
   
   	case 3:
   		cout<<"Grocery items"<<endl;
	item.traversing(); // calling traversing function to display items
		break;
		
    
}
}while(true);
}
}
