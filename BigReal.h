#pragma once
#include "BigDecimalIntClass.h"
#include<sstream>
#include<math.h>
#include<iomanip>
class BigReal
{
private:
    BigDecimalInt intPart;
    vector<int> decPart;

public:
    BigReal(double realNumber = 0); // Default constructor
    BigReal(string realNumber);
    BigReal(BigDecimalInt bigInteger);
    //BigReal(BigReal& other);       // Copy constructor
    //BigReal(BigReal&& other);            // Move constructor
    //BigReal& operator=(BigReal& other);  // Assignment operator
    //BigReal& operator=(BigReal&& other); // Move assignment
    BigReal operator+(BigReal other);
    BigReal operator-(BigReal other);
    bool operator<(BigReal anotherReal);
    bool operator>(BigReal anotherReal);
    bool operator==(BigReal anotherReal);
    int size();
    int sign();
    friend ostream& operator<<(ostream& out, BigReal num);
    //friend istream& operator>>(istream& out, BigReal num);
};
