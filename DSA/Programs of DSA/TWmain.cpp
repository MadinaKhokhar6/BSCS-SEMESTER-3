#include <iostream>
#include "TWLinkedList.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	TWLinkedList<int> list1;
	list1.addToHead(25);
	list1.addToHead(20);
	list1.addToHead(10);
	list1.addToTail(30);
	list1.addAfter(10,15);
	list1.addAfter(15,13);
	//10 13 15 20 25 30
	list1.traversing();
	cout<<endl;
	list1.traverseBackward();
	return 0;
}
