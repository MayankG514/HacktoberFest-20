#include <iostream>
 
using namespace std;
 
int main(){
float a, b, res;
	char choice, ch;
		cout<<"1.Addition\n";
		cout<<"2.Subtraction\n";
		cout<<"3.Multiplication\n";
		cout<<"4.Division\n";
		cout<<"Enter Your Choice : ";
		cin>>choice;
		switch(choice)
		{
			case '1' : cout<<"Enter two number : ";
				cin>>a>>b;
				res=a+b;
				cout<<"a+b";
				cout<<"Result = "<<res;
				break;
			case '2' : cout<<"Enter two number : ";
				cin>>a>>b;
				res=a-b;
				cout<<"a-b";
				cout<<"Result = "<<res;
				break;
			case '3' : cout<<"Enter two number : ";
				cin>>a>>b;
				res=a*b;
				cout<<"a*b";
				cout<<"Result = "<<res;
				break;
			case '4' : cout<<"Enter two number : ";
				cin>>a>>b;
				res=a/b;
				cout<<"a/b";
				cout<<"Result = "<<res;
				break;
				
			default : cout<<"Wrong Choice..!!";
				break;
		}
		return 0;
	}