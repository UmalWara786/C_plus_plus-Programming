// Bank Account Management System

#include <iostream>
// File Handling
#include <fstream>
// Manipulating with Strings
#include <sstream>
// Console Design
#include <windows.h>
using namespace std;

class Account {
private:
  string Accountno, Password, name;
  int Balance;
public:
  Account(): name(""), Accountno(""), Password(""), Balance(0) {}

  void setAccountno(string id) { Accountno = id; }
  void setPassword(string p) { Password = p; }
  void setBalance(int B) { Balance = B; }
  void setname(string n) { name = n; }

  string getAccountno() { return Accountno; }
  string getPassword() { return Password; }
  int getBalance() { return Balance; }
  string getname() { return name; }
};

// Function to create new account
void OpenAccount(Account user) {
    system("cls"); 
// Background Colour    
    system("color 70");
    string id, p, name;
    
// Text Color    
  HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);    
  SetConsoleTextAttribute(h,15);
  cout<<"\n\n\n\n\n";
  cout<<"\t\t\t\t\t\t  Account Creation "<<endl;
  cout<<"\t\t\t\t\t\t*------------------*"<<endl<<endl;
  cout<<"\t\t\t\t\t\t Enter your name : ";
  cin.ignore();  // ignore leftover newline
  getline(cin, name);
  cout<<"\t\t\t\t\t\t Enter Account no : ";
  cin>>id;
  cout<<"\t\t\t\t\t\t Enter a strong password : ";
  cin>>p;
    
  user.setname(name);
  user.setAccountno(id);
  user.setPassword(p);
  user.setBalance(0);
    
  ofstream outfile("F:/Account.txt", ios::app);
  if(!outfile)
  cout<<"\t\t\t\t\t\tError: File can't open!"<<endl;
  else {
  outfile << user.getname() << ":" << user.getAccountno() << ":" << user.getPassword() << ":" << user.getBalance() << endl;
  SetConsoleTextAttribute(h,6);
  cout<<"\t\t\t\t\t\tAccount has been created successfully!"<<endl<<endl<<endl;
    }
  Beep(500,200);
  cout<<"\t\t\t\t\t\tYour Current Balance : "<<user.getBalance()<<endl;
  outfile.close();
  Sleep(5000);    
}

// Function to deposit money
void Addmoney() {
  system("cls");
  system("color B7");
  string id;
  HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(h, 7);
  cout<<"\n\n\n\n\n";
  cout<<"\t\t\t\t\t\t  Deposit Money "<<endl;
  cout<<"\t\t\t\t\t\t*---------------*"<<endl<<endl;
  cout<<"\t\t\t\t\t\tEnter Account no : ";
  cin>>id;

  ifstream infile("F:/Account.txt");
  ofstream outfile("F:/AccountTemp.txt");

  if(!infile || !outfile){
  cout<<"Error: File can't open!"<<endl;
  return;
    }

  string line;
  bool found=false;
  int cash = 0;

  while(getline(infile,line)){
  string username, userID, userP, balanceStr;
  int userBalance;

  stringstream ss(line);
  getline(ss, username, ':');
  getline(ss, userID, ':');
  getline(ss, userP, ':');
  getline(ss, balanceStr, ':');

  stringstream convert(balanceStr);
  convert >> userBalance;

  if(id==userID && !found){ // Only prompt once
  found=true;     
  cout<<"\t\t\t\t\t\tEnter cash : ";
  cin>>cash;
  userBalance += cash;
  SetConsoleTextAttribute(h, 2);
  cout<<"\t\t\t\t\t\tNew Balance is : "<<userBalance<<endl;
  Beep(659,200);
    }

  outfile << username << ":" << userID << ":" << userP << ":" << userBalance << endl;
    }

  if(!found){
  SetConsoleTextAttribute(h,4);
  cout<<"\t\t\t\t\t\tEnter valid Account no!"<<endl;
    }

  outfile.close();
  infile.close();
  remove("F:/Account.txt");
  rename("F:/AccountTemp.txt","F:/Account.txt");    
  Sleep(4000);
}

// Function to withdraw money
void withdraw() {
  system("cls");
  system("color F0");
  string id,p;
  HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(h,6);
  cout<<"\n\n\n\n\n";
  cout<<"\t\t\t\t\t\t Withdraw Money "<<endl;
  cout<<"\t\t\t\t\t\t*--------------*"<<endl;
  cout<<"\t\t\t\t\t\tEnter Account no : ";
  cin>>id;
  cout<<"\t\t\t\t\t\tEnter Password : ";
  cin>>p;

  ifstream infile("F:/Account.txt");
  ofstream outfile("F:/AccountTemp.txt");

  if(!infile||!outfile){
  cout<<"\t\t\t\t\t\tError: File can't open!"<<endl;
  return;
    }

  string line;
  bool found=false;

  while(getline(infile,line)){
  string username, userID, userP, balanceStr;
  int userBalance;

  stringstream ss(line);
  getline(ss, username, ':');
  getline(ss, userID, ':');
  getline(ss, userP, ':');
  getline(ss, balanceStr, ':');

  stringstream convert(balanceStr);
  convert >> userBalance;

  if(id==userID && p==userP && !found){
  found=true;
  int cash;
  cout<<"\t\t\t\t\t\tEnter Cash : ";
  cin>>cash;
  if(cash <= userBalance){
  userBalance -= cash;
  SetConsoleTextAttribute(h, 2);
  cout<<"\t\t\t\t\t\tTransaction was Successful!"<<endl;
  Beep(900,200);
  cout<<"\t\t\t\t\t\tRemaining Balance : "<<userBalance<<endl;    
    }
  else{
  SetConsoleTextAttribute(h,4);
  cout<<"\t\t\t\t\t\tLow Balance!"<<endl;
    }
    }

  outfile << username << ":" << userID << ":" << userP << ":" << userBalance << endl;
    }

  if(!found){
  SetConsoleTextAttribute(h,7);
  cout<<"\t\t\t\t\t\tInvalid Account no. or Password!"<<endl;
    }

  outfile.close();
  infile.close();
  remove("F:/Account.txt");
  rename("F:/AccountTemp.txt","F:/Account.txt");    
  Sleep(4000);
}

// Function to check balance
void CheckBalance() {
  system("cls");
  system("color E0");
  string id, p;
  HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(h, 3);
  cout<<"\n\n\n\n\n";
  cout<<"\t\t\t\t\t\t Check Balance "<<endl;
  cout<<"\t\t\t\t\t\t*--------------*"<<endl;
  SetConsoleTextAttribute(h, 6);
  cout<<"\t\t\t\t\t\tEnter Account no : ";
  cin>>id;
  cout<<"\t\t\t\t\t\tEnter Password : ";
  cin>>p;

  ifstream infile("F:/Account.txt");
  if(!infile){
  cout<<"Error: File can't open!"<<endl;
  return;
    }

  string line;
  bool found=false;
  while(getline(infile,line)){
  string username, userID, userP, balanceStr;
  int userBalance;
  stringstream ss(line);
  getline(ss, username, ':');
  getline(ss, userID, ':');
  getline(ss, userP, ':');
  getline(ss, balanceStr, ':');
  stringstream convert(balanceStr);
  convert >> userBalance;

  if(userID==id && userP==p){
  found=true;
  SetConsoleTextAttribute(h, 2);
  cout<<"\t\t\t\t\t\tHello "<<username<<"!"<<endl;
  cout<<"\t\t\t\t\t\tYour Current Balance is : "<<userBalance<<endl;
  break;
    }
    }

  if(!found){
  SetConsoleTextAttribute(h, 4);
  cout<<"\t\t\t\t\t\tInvalid Account no. or Password!"<<endl;
    }

  infile.close();
  Sleep(4000);
}

int main() {
  Account user;
  system("color 37");    
  bool exit=false;
  while(!exit){
  system("cls");    
  int var;
  HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(h,30);
  cout<<endl<<endl;
  cout<<"\t\t\t\t\t\t\t |=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=**=*=*=*|"<<endl;
  cout<<"\t\t\t\t\t\t\t |Welcome To Bank Account Management System\t   |"<<endl;
  cout<<"\t\t\t\t\t\t\t |=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=**=*=*=*|"<<endl;
  cout<<"\t\t\t\t\t\t\t |\tDeveloped by: Umal wara\t                   |"<<endl;
  cout<<"\t\t\t\t\t\t\t |=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=**=*=*=*|"<<endl<<endl;
  SetConsoleTextAttribute(h, 3);
  cout<<"\t\t\t\t\t\t\t\t\t 1. Open new Account"<<endl;
  cout<<"\t\t\t\t\t\t\t\t\t 2. Add Cash"<<endl;
  cout<<"\t\t\t\t\t\t\t\t\t 3. Withdraw Cash"<<endl;
  cout<<"\t\t\t\t\t\t\t\t\t 4. Check Balance"<<endl;
  cout<<"\t\t\t\t\t\t\t\t\t 5. Exit"<<endl;     
  SetConsoleTextAttribute(h, 7);
  cout<<"\t\t\t\t\t\t\t\t\tEnter your choice : ";
  cin>>var;
// Beep Sounds    
  Beep(700,200);
  if(var==1) OpenAccount(user);
  else if(var==2) Addmoney();
  else if(var==3) withdraw();
  else if(var==4) CheckBalance();
  else if(var==5){    	
  system("cls");
  exit=true;
  cout<<endl<<endl<<endl<<endl;
  SetConsoleTextAttribute(h,30);
  system("color B0");
  cout<<"\t\t\t\t\t\t\tThank you for visiting my Bank Account Management System!"<<endl;
  cout<<"\t\t\t\t\t\t\t\t\tHave a nice day!"<<endl;
// Slightly Pause Between Screens    
  Sleep(2000); 
    }
    }

  Sleep(3000);    
  return 0;
}
