#include "mString.h"


//===========================================
//
// Implementing class methods
//
//===========================================


mString::mString()
{
    mainStr = nullptr;
}

mString::mString(std::string str)
{
    mainStr = new char[str.size()];
    std::copy(str.begin(), str.end(), mainStr);
    mainStr[str.size()] = '\0';
}

mString::mString(char* str)
{
    mainStr = str;
}

mString::mString(const char* str)
{
    mainStr = _strdup(str);
}

mString::mString(mString* str)
{
    mainStr = str->mainStr;
}


mString::~mString()
{
}


mString& mString::operator=(std::string str)
{
    mainStr = new char[str.size()];
    std::copy(str.begin(), str.end(), mainStr);
    mainStr[str.size()] = '\0';
    return *this;
}


mString& mString::operator+=(std::string str)
{
    char* oldStr = mainStr;
    mainStr = (char*)malloc(strlen(oldStr) + str.size());

    return *this;
}


mString& mString::operator=(mString* str)
{
    mainStr = str->mainStr;
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
