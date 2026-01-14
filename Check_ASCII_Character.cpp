//This program checks the Alphabetical character whether it's a Upper Or Lower case

#include<iostream>
#include<conio.h>
using namespace std;
int main(){
char lett;
cout<<"Enter any character : ";
cin>>lett;
if((lett>=65)&&(lett<=90)){
  cout<<"Upper case";
	}
else if((lett>=97)&&(lett<=122)){
  cout<<"Lower case";
    }
else{
  cout<<"It is nither upper nor lower case";
	}
return 0;
}
