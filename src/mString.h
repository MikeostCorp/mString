#pragma once
#include <iostream>

class mString {

private:
    char* mainStr;
    size_t sizeStr;

public:

    //===========================
    // 
    // Constructors
    //
    //===========================

    mString();                 // default constuctor
    mString(std::string str);  // constructor for string
    mString(mString* str);     // constructor for mString
    mString(char* str);        // constructor for char
    mString(const char* str);  // constctor for const char
    mString(const mString &mStr);
    ~mString();                // destructor


    //=============================================
    // 
    // Overload operators
    //
    //=============================================

    mString& operator = (std::string str);       // overload operator for just string =
    mString& operator = (mString str);          // overload operator for string myString =
    mString& operator = (char* str);             // overload operator for char string =
    mString& operator = (const char* str);       // overload operator for const char =

    mString& operator += (std::string str);      // overload operator for just string +=
    mString& operator += (mString str);          // overload operator for just mString +=
    mString& operator += (char* str);            // overload operator for char string +=
    mString& operator += (const char* str);      // overload operator for const char +=


    //===========================================================================
    //
    // Class friends
    //
    //============================================================================

    friend std::ostream& operator<< (std::ostream& out, const mString& myStr);  // cout myString
    friend std::istream& operator>> (std::istream& in, mString& myStr);         // cin myString


    //============================
    //
    // Methods for myString
    //
    //============================

    char chartAt(int num);       // returns the character at the given number
    int length();                // string length
    mString toUpStr();           // converts a string to uppercase
    mString toLowStr();          // converts string to lower case
    char* getText();
};
