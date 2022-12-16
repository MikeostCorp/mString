#pragma once
#include <iostream>

class mString {

private:
    char* mainStr;

public:
    mString();                 // default constuctor
    mString(std::string str);  // constructor for string
    mString(char* str);        // constructor for char
    mString(const char* str);  // constctor for const char
    mString(mString* str);     // constructor for mString
    ~mString();                // destructor

    //=========================
    // 
    // Overload operators
    //
    //=========================

    mString& operator = (std::string str);    // overload operator for just string =
    mString& operator = (mString* str);       // overload operator for string myString =
    mString& operator = (char* str);          // overload operator for char string =
    mString& operator += (std::string str);   // overload operator for just string +=
    // mString& operator += (myString str);   // overload operator for just myString +=
    //mString& operator += (char* str);       // overload operator for char string +=

    friend std::ostream& operator<< (std::ostream& out, const mString& myStr);  // couter myString
    friend std::istream& operator>> (std::istream& in, mString& myStr);         // cin myString

    //=========================
    //
    // Methods for myString
    //
    //=========================

    // mString number(int num);

};
