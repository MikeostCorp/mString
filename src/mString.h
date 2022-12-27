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

    mString();                      // default constuctor
    mString(const std::string str); // constructor for string
    mString(const mString* str);    // constructor for mString
    mString(const char* str);       // constructor for const char
    mString(const mString& mStr);   // constructor for copy
    ~mString();                     // destructor


    //==============================================
    // 
    // Overload operators
    //
    //==============================================

    mString& operator = (mString str);            // overload operator for just myString =
    mString& operator = (const std::string str);  // overload operator for just string =
    mString& operator = (const char* str);        // overload operator for const char =

    mString& operator += (mString str);           // overload operator for just mString +=
    mString& operator += (const std::string str); // overload operator for just string +=
    mString& operator += (const char* str);       // overload operator for const char +=


    //============================================================================
    //
    // Class friends
    //
    //============================================================================

    friend std::ostream& operator<< (std::ostream& out, const mString& myStr);  // cout myString
    friend std::istream& operator>> (std::istream& in, mString& myStr);         // cin myString


    //========================================
    //
    // Methods for myString
    //
    //========================================

    size_t length();                        // string length
    char charAt(const size_t num);          // returns the character at the given index
    char at(const size_t num);              // return the character at the given index from the end of the string
    mString toUpStr();                      // converts a string to uppercase
    mString toLowStr();                     // converts a string to lower case
    char* getTextChar();                    // returns a string of type char
    bool beginWith(const char bChar);       // returns true or false depending on which given character the string starts with
    bool endWith(const char eChar);         // returns true or false depending on the given character at the end of the string
    bool includes(const char iChar);        // returns true or false depending on whether the string includes the given character
    size_t indexChar(const char iChar);     // return the first available character index in the string. Returns 0 if the character is not found in the string
    size_t lastIndexChar(const char lChar); // returns the last available character index in the string. Returns 0 if the character is not found in the string
    size_t searchCount(const char sChar);   // returns the number of repetitions of a character in a string
};
