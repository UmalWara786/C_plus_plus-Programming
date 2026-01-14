#include <iostream>
#include<windows.h>
using namespace std;

// Base class for converters
class Converter {
public:
virtual void displayOptions() = 0;
virtual void convert() = 0;
};

// Temperature Converter Class
class TemperatureConverter : public Converter {
public:
	
void displayOptions()  {
// To clear Screen before next step    	
    system ("cls");
// Background colour   	
    system("color 30");
    cout<<endl<<endl<<endl<<endl;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
// Text colour    	
    SetConsoleTextAttribute(h, 15);
    cout << "\n\t\t\t\t\t\t\tTemperature Conversion Options:\n"<<endl;
    SetConsoleTextAttribute(h,11 );
    cout << "\t\t\t\t\t\t\t1. Celsius to Fahrenheit\n";
    cout << "\t\t\t\t\t\t\t2. Fahrenheit to Celsius\n";
    cout << "\t\t\t\t\t\t\t3. Celsius to Kelvin\n";
    cout << "\t\t\t\t\t\t\t4. Kelvin to Celsius\n";
    cout << "\t\t\t\t\t\t\t5. Fahrenheit to Kelvin\n";
    cout << "\t\t\t\t\t\t\t6. Kelvin to Fahrenheit\n";
    }

void convert()  {
    int choice;
    double temp, result;
    displayOptions();
    cout<<endl<<endl<<endl<<endl;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 7);
    cout << "\n\t\t\t\t\t\t\tEnter your choice: ";
    cin >> choice;
    if(choice<7 && choice>0){
    cout << "\t\t\t\t\t\t\tEnter the temperature: ";
    cin >> temp;}
    Beep(700,200);

    switch (choice) {
    case 1: result = (temp * 9/5) + 32; cout << "\t\t\t\t\t\t\tResult: " << result << " Â°F\n"; break;
    case 2: result = (temp - 32) * 5/9; cout << "\t\t\t\t\t\t\tResult: " << result << " Â°C\n"; break;
    case 3: result = temp + 273.16; cout << "\t\t\t\t\t\t\tResult: " << result << " K\n"; break;
    case 4: result = temp - 273.16; cout << "\t\t\t\t\t\t\tResult: " << result << " Â°C\n"; break;
    case 5: result = (temp - 32) * 5/9 + 273.16; cout << "\t\t\t\t\t\t\tResult: " << result << " K\n"; break;
    case 6: result = (temp - 273.16) * 9/5 + 32; cout << "\t\t\t\t\t\t\tResult: " << result << " Â°F\n"; break;
    default: cout << "\t\t\t\t\t\t\tInvalid choice!\n"; break;
        }
// To pause between different screens        
    Sleep(4000);
    }
    
};

// Length Converter Class
class LengthConverter : public Converter {
public:
   void displayOptions()  {
    system ("cls");
    system("color B7");
    cout<<endl<<endl<<endl<<endl;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 15);
    cout << "\n\t\t\t\t\t\t\tLength Conversion Options:\n"<<endl;
    SetConsoleTextAttribute(h, 2);
    cout << "\t\t\t\t\t\t\t1. Kilometers to Meters\n";
    cout << "\t\t\t\t\t\t\t2. Meters to Kilometers\n";
    cout << "\t\t\t\t\t\t\t3. Meters to Centimeters\n";
    cout << "\t\t\t\t\t\t\t4. Centimeters to Meters\n";
    cout << "\t\t\t\t\t\t\t5. Kilometers to Centimeters\n";
    cout << "\t\t\t\t\t\t\t6. Centimeters to Kilometers\n";
    }

   void convert()  {
    int choice;
    double length, result;
    displayOptions();
    cout<<endl<<endl<<endl<<endl;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h,6);
    cout << "\t\t\t\t\t\t\tEnter your choice: ";
    cin >> choice;
    if(choice<7 && choice>0){
    cout << "\t\t\t\t\t\t\tEnter the length: ";
    cin >> length;}
    Beep(750, 300);

  switch (choice) {
    case 1: result = length * 1000; cout << "\t\t\t\t\t\t\tResult: " << result << " m\n"; break;
    case 2: result = length / 1000; cout << "\t\t\t\t\t\t\tResult: " << result << " km\n"; break;
    case 3: result = length * 100; cout << "\t\t\t\t\t\t\tResult: " << result << " cm\n"; break;
    case 4: result = length / 100; cout << "\t\t\t\t\t\t\tResult: " << result << " m\n"; break;
    case 5: result = length * 100000; cout << "\t\t\t\t\t\t\tResult: " << result << " cm\n"; break;
    case 6: result = length / 100000; cout << "\t\t\t\t\t\t\tResult: " << result << " km\n"; break;
    default: cout << "\t\t\t\t\t\t\tInvalid choice!\n"; break;
        }
    Sleep(4000);
    }
};

// Time Converter Class
class TimeConverter : public Converter {
public:
  void displayOptions()  {
    system ("cls");
    system("color F0");
    cout<<endl<<endl<<endl<<endl;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 15);
    SetConsoleTextAttribute(h,14 );
    cout << "\t\t\t\t\t\t\t1. Minutes to Seconds\n";
    cout << "\t\t\t\t\t\t\t2. Seconds to Minutes\n";
    cout << "\t\t\t\t\t\t\t3. Minutes to Hours\n";
    cout << "\t\t\t\t\t\t\t4. Hours to Minutes\n";
    cout << "\t\t\t\t\t\t\t5. Hours to Seconds\n";
    cout << "\t\t\t\t\t\t\t6. Seconds to Hours\n";
    }

  void convert()  {
    int choice;
    double time, result;
    displayOptions();
    cout<<endl<<endl<<endl<<endl;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 3);
    cout << "\t\t\t\t\t\t\tEnter your choice: ";
    cin >> choice;
    if(choice<7 && choice>0){
    cout << "\t\t\t\t\t\t\tEnter the time: ";
    cin >> time;}
    Beep(750, 300);

  switch (choice) {
    case 1: result = time * 60; cout << "\t\t\t\t\t\t\tResult: " << result << " sec\n"; break;
    case 2: result = time / 60; cout << "\t\t\t\t\t\t\tResult: " << result << " min\n"; break;
    case 3: result = time / 60; cout << "\t\t\t\t\t\t\tResult: " << result << " hr\n"; break;
    case 4: result = time * 60; cout << "\t\t\t\t\t\t\tResult: " << result << " min\n"; break;
    case 5: result = time * 3600; cout << "\t\t\t\t\t\t\tResult: " << result << " sec\n"; break;
    case 6: result = time / 3600; cout << "\t\t\t\t\t\t\tResult: " << result << " hr\n"; break;
    default: cout << "\t\t\t\t\t\t\tInvalid choice!\n"; break;
        }
    Sleep(4000);
    }
};

int main() {
  int choice;
  Converter* converter;
  while (true) {
  system("cls");
  system("color F0");
  HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

  SetConsoleTextAttribute(h,15);
    
    cout<<"\n\n\n\n\t\t\t\t\t\t\t===================================" <<endl
				<<"\t\t\t\t\t\t\t| \t\t                  |" <<endl
				<<"\t\t\t\t\t\t\t| Physical Quantities CONVERTER   |" <<endl
				<<"\t\t\t\t\t\t\t| \t\t                  |" <<endl
				<<"\t\t\t\t\t\t\t| Software Developed By Umal wara |" <<endl
				<<"\t\t\t\t\t\t\t| \t\t                  |" <<endl
				<<"\t\t\t\t\t\t\t| \t\t                  |" <<endl
				<<"\t\t\t\t\t\t\t===================================" <<endl
				<<"\n\t\t\t\t\t\t\t";
			
    
   SetConsoleTextAttribute(h, 4);
   cout << "\n\t\t\t\t\t\t\t\tConverter:\n";
   SetConsoleTextAttribute(h, 3);
   cout << "\t\t\t\t\t\t\t\t1. Temperature Converter\n";
   cout << "\t\t\t\t\t\t\t\t2. Length Converter\n";
   cout << "\t\t\t\t\t\t\t\t3. Time Converter\n";
   cout << "\t\t\t\t\t\t\t\t4. Exit\n";
   cout << "\t\t\t\t\t\t\t\tEnter your choice: ";
   cin >> choice;
// Beep Sound        
   Beep(15000, 400); // Frequency 15000 Hz, duration 400 ms


  switch (choice) {
   case 1: converter = new TemperatureConverter(); break;
   case 2: converter = new LengthConverter(); break;
   case 3: converter = new TimeConverter(); break;
   case 4: cout << "\n\n\t\t\t\t\t\t\t      Exiting program. Goodbye!\n"; return 0;
   default: cout << "\n\n\t\t\t\t\t\t\t       Invalid choice! Try again.\n"; return 0;
        }

   converter->convert();
   delete converter;
    
    }

return 0;
}
