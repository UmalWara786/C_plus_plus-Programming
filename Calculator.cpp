#include<iostream>
using namespace std;

int main(){
	int a,b;
	char op;
	cout<<"Enter first number : ";
	cin>>a;
	cout<<"Enter second number : ";
	cin>>b;
	cout<<"Enter operator : ";
	cin>>op;
// Ternary Operator  
	int result = (op== '+') ? ( a + b): 
	             (op== '-') ? ( a - b):
	             (op== '*') ? ( a * b): 
	             (op== '/') ? ( a / b): 
					     (op== '%') ? ( a % b): 0;
	cout<<a<<" "<<op<<" "<<b<<" = "<<result;			
	return 0;
}
