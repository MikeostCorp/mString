#include "mString.h"

//===========================================
//
// Implementing class methods
//
//===========================================


mString::mString()
{
    mainStr = 0;
}

mString::~mString()
{
}

mString& mString::operator=(std::string str)
{
    mainStr = const_cast<char*>(str.c_str());
    return *this;
}

mString& mString::operator=(mString* str)
{
    //  mainStr = newstr;
    return *this;
}

mString& mString::operator=(char* str)
{
    mainStr = str;
    return *this;
}

std::ostream& operator<<(std::ostream& out, const mString& myStr)
{
    out << myStr.mainStr;
    return out;
}

std::istream& operator>>(std::istream& in, mString& myStr)
{
    in >> myStr.mainStr;
    return in;
}