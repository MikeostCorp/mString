#pragma once
#include <iostream>

class mString {

private:
    char* mainStr;
    size_t sizeStr;

public:

    //=============================
    // 
    // Constructors
    //
    //=============================

    mString();                    // default constuctor
    mString(std::string str);     // constructor for string
    mString(mString* str);        // constructor for mString
    mString(char* str);           // constructor for char
    mString(const char* str);     // constructor for const char
    mString(const mString& mStr); // constructor for copy
    ~mString();                   // destructor


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


    //=================================
    //
    // Methods for myString
    //
    //=================================

    char chartAt(int num);           // returns the character at the given number
    int length();                    // string length
    mString toUpStr();               // converts a string to uppercase
    mString toLowStr();              // converts string to lower case
    char* getTextChar();             // returns a string of type char
    bool beginWith(char bChar);      // returns true or false depending on which given character the string starts with
    bool endWith(char eChar);        // returns true or false depending on the given character at the end of the string
    bool includes(char iChar);       // returns true or false depending on whether the string includes the given character
    int indexChar(char iChar);       // return the first available character index in the string. Returns 0 if the character is not found in the string
    int lastIndexChar(char lChar);   // returns the last available character index in the string.Returns 0 if the character is not found in the string
    size_t searchCount(char sChar);  // returns the number of repetitions of a character in a string
};
