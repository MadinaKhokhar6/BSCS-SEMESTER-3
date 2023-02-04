#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	ofstream myfile;
	myfile.open("example1.txt");
	myfile<<"ID-Name-Description-price";
	myfile<<"123 Esha Data Structure And Algorithm 1230";
	myfile<<" 234 Madina Digital logic and Design 1239";
	myfile.close();
ifstream Myfile;
Myfile.open("example1.txt");
 char ch[1000];
 Myfile.getline(ch,100);                  // reading
cout<<ch;                            // display on screen
Myfile.close();
}


