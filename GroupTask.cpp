//Asmaa Elawady Ibrahim    20210068
//Asmaa saleh farghaly     20211014
//Rawan Hesham Hamdy       20211040


#include <bits/stdc++.h>
#include"BigDecInt.h"
#include "BigDecInt.cpp"

using namespace std;

int main() {
    string num1, num2 ;
    cout << "***********Hello***********\n";
    cout << "***********Welcome To Big Integers Calculator***********\n";
    cout << "Please enter the first number = " ;
    getline(cin, num1);
    while(!(regex_match(num1,regex("[+-]?[0-9]+")))){
        cout << "NOT VALID, Please enter a valid number = ";
        getline(cin, num1);
    }
    BigDecimalInt b(num1) ;
    cout << "Please enter the second number = " ;
    getline(cin, num2);
    while(!(regex_match(num2,regex("[+-]?[0-9]+")))){
        cout << "NOT VALID, Please enter a valid number = ";
        getline(cin, num2);
    }
    BigDecimalInt b1(num2);
    cout << " Operator+ = " << b + b1 << endl ;
    if(b == b1) {
        cout << "The Two numbers are equal.\n";
    }else {
        cout << "The Two numbers are not equal.\n";
    }
    if (b > b1) {
        cout << "First number is greater than Second number\n";
    } else if (b == b1) {
        cout << "First number equals Second number.\n";
    } else if(b < b1) {
        cout << "First number is smaller than Second number\n";
    }
    cout <<" Operator- = "<<b - b1<<endl;
    BigDecimalInt b2 = b1;
    cout << "Assignment operator (new number = second number) = " << b2;
}

