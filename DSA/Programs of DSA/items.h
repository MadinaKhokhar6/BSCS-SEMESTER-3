#include<iostream>
using namespace std;
class items
{
private:
string itemName,uniqueId,description,price; // declaring variables
double quantity;
public: // constructor
items(string name="",string id="",string des="",string pri="")
{
itemName=name;// passing values
uniqueId=id;
description=des;
price=pri;
} // declaring functions
void setquan(double q);
double getquan();
void setId(string id);
string getId();
void displayInfo();
void setDes(string descr);
string getDes();
void setPrice(string pri);
string getPrice();
void setName(string name);
string getName();
};

void items::displayInfo(){ // displaying info 
cout<<itemName<<" "<<uniqueId<<" "<<description<<" "<<price<<endl;
}
void items::setquan(double q){ // setting quantity
    quantity=q;
}
void items::setId(string id){ // setting id
    uniqueId=id;
}
void items::setDes(string descr){ // setting description
    description=descr;
}
void items::setPrice(string pri){ // setting price
    price=pri;
}
void items::setName(string name){ // setting name of product
    itemName=name;
}
string items::getDes(){ // getting description
    return description;
}
string items::getPrice(){ // getting price
    return price;
}
string items::getName(){ // getting name
    return itemName;
}
string items::getId(){ // getting id
    return uniqueId;
}
double items::getquan(){ // getting quantity
    return quantity;
}
