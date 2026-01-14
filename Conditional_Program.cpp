// This program takes 3 values from user and in return provide larger and smaller value from three of them.

#include<iostream>
using namespace std;

int main(){
int a,b,c;                            
cout<<"Enter first number : ";        
cin>>a;                               
cout<<"Enter second number: ";        
cin>>b;                               
cout<<"Enter third number : ";        
cin>>c; 
  
// For Large value                    
if((a>b)&&(a>c)){                     
	cout<<"Greater value : "<<a<<endl;
}                                     
else if((b>a)&&(b>c)){                
	cout<<"Greater value : "<<b<<endl;
}                                     
else {                                
	cout<<"Greater value : "<<c<<endl;
} 
  
// For Small value                    
if((a<b) && (a<c)){                   
	cout<<"Smaller value : "<<a<<endl;
}                                     
else if((b<c) && (b<a)){              
	cout<<"Smaller value : "<<b<<endl;
}                                     
else{                                 
	cout<<"Smaller value : "<<c<<endl;
}
return 0;
}
