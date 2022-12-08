#pragma once
#include <iostream>

class mString {

private:
    char* mainStr;

public:
    mString(); // constuctor
    ~mString(); // destructor

    //=========================
    // 
    // Overload operators
    //
    //=========================

    mString& operator = (std::string str); // overload operator for just string =
    // myString& operator += (std::string str); // overload operator for just string +=
    mString& operator = (mString* str); // overload operator for string myString =
    // myString& operator += (myString str); // overload operator for just myString +=
    mString& operator = (char* str);  // overload operator for char string =
    //  myString& operator += (char* str);  // overload operator for char string +=

    friend std::ostream& operator<< (std::ostream& out, const mString& myStr); // couter myString
    friend std::istream& operator>> (std::istream& in, mString& myStr); // cin myString

    //=========================
    //
    // Methods for myString
    //
    //=========================

    char toChar(mString* str); // to char for myString
    // mString number(int num)
    // {
    //     return 0;
    // }
};