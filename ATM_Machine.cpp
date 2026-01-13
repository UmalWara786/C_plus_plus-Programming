#include<iostream>
using namespace std;

int main(){
	//ATM Program
	int choice;
	//Previous amount in User's Account 
	int balance = 4000;
	int amount;
	cout<<"Select your desired menu : "<<endl;
	cout<<"1. Check Balance"<<endl;
	cout<<"2. Deposit"<<endl;
	cout<<"3. Withdraw"<<endl;
	cout<<"Enter your desired menu number : ";
	cin>>choice;
	
	switch(choice){
	case 1:{    //Check Balance
		cout<<"Balance : ";
		cout<<balance;
		break;
	}
	case 2:{     //Deposit
		cout<<"Enter amount for deposit : ";
		cin>>amount;
		balance+=amount;
		cout<<"Current balance : ";
		cout<<balance;
		break;
	}
	case 3:{   //Withdraw
		cout<<"Enter amount to withdraw : ";
		cin>>amount;
		if((amount<=balance)&&(amount%100==0)){
			balance-=amount;
			cout<<"Current balance : ";
			cout<<balance;	
		}
			else{
			cout<<"No valid amount!";
		}	
		break;
	}
	default:{
		cout<<"No valid outcomes";
		break;
	}
	}
	return 0;
}
