#include "mString.h"

//===========================================
//
// Implementing class methods
//
//===========================================


mString::mString()
{
    //mainStr = 0;
    mainStr = static_cast<char*>(malloc(sizeof(char) * 1));
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
    mainStr = strdup(str);
}

mString::mString(mString* str)
{
    mainStr = str->mainStr;
}


mString::~mString()
{
    //free(mainStr);
}

mString& mString::operator=(std::string str)
{
    mainStr = const_cast<char*>(str.c_str());
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

mString& mString::operator+=(std::string str)
{   
    char *temp = static_cast<char*>(malloc(sizeof(mainStr) * strlen(mainStr)));
    strcpy(temp, mainStr);
    mainStr = static_cast<char*>(malloc(strlen(this->mainStr) + str.size() + 1));
    strcat(mainStr, temp);
    strcat(mainStr, str.c_str());

    return *this;
}