#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	fstream myfile;
	myfile.open("example1.txt");
	myfile<<"ID-Name-Description-price"<<endl<<endl;
	myfile<<"123 Esha Data Structure And Algorithm 1230"<<endl<<endl;
	myfile<<"234 Madina Digital logic and Design 1239"<<endl;
	myfile.close();
ifstream Myfile;
Myfile.open("example1.txt");
 char ch[1000];
 Myfile.getline(ch,1000);                  // reading
cout<<ch;                            // display on screen
Myfile.close();
}


