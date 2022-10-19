#ifndef UNTITLED1_BIGDECINT_H
#define UNTITLED1_BIGDECINT_H

#include <bits/stdc++.h>

using namespace std;

class BigDecimalInt{
private:
    vector <int> vec;
    char s; // for the sign.
public:
    // default constructor
    BigDecimalInt (){}
    // parameterized constructor (takes integer)
    BigDecimalInt (int decInt);
    // parameterized constructor (takes string)
    BigDecimalInt (string decStr);

    // Getters and Setters for private attributes.
    void setVec (vector <int> v);
    vector<int> getVector ();
    void setS(char sign);
    char getS();

    // function to check the size of the two numbers and makes them equal.
    void checkSize(vector <int>& v1,vector <int>& v2);

    // overload for operator + to add two big numbers.
    BigDecimalInt operator+ (BigDecimalInt anotherDec);

    // overload for operator < to know if the first number is smaller than the second one or not.
    bool operator< (BigDecimalInt b);

    // overload for operator > to know if the first number is bigger than the second one or not.
    bool operator> (BigDecimalInt b);

    // overload for operator == to chech if the two numbers are equals.
    bool operator== (BigDecimalInt b);

    // overload for = (assign operator) to make two object's attributes equal to each other.
    bool operator= (BigDecimalInt b);

    // function to return the size (length) of the number.
    int size();

    // function to return the sign of the number.
    char sign();

    // overload for operator - to subtract two big numbers.
    BigDecimalInt operator- (BigDecimalInt anotherDec);

    // overload for operator << to print the number.
    friend ostream& operator<< (ostream& out, BigDecimalInt a);

    void subtraction(vector <int>& v1,vector <int>& v2);
    void addition(vector <int>& v1,vector <int>& v2);
};

#endif //UNTITLED1_BIGDECINT_H