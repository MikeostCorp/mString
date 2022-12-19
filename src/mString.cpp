#include "mString.h"

#define strdup _strdup

//===========================================
//
// Implementing class methods
//
//===========================================

mString::mString()
{
    mainStr = static_cast<char*>(malloc(sizeof(char) * 1));
}

mString::mString(std::string str)
{
    mainStr = strdup(str.c_str());
}

mString::mString(mString* str)
{
    mainStr = strdup(str->mainStr);
}

mString::mString(char* str)
{
    mainStr = strdup(str);
}

mString::mString(const char* str)
{
    mainStr = strdup(str);
}

mString::~mString()
{
  // free(mainStr);
}

mString& mString::operator=(std::string str)
{
    mainStr = strdup(str.c_str());
    return *this;
}

mString& mString::operator=(mString* str)
{
    mainStr = strdup(str->mainStr);
    return *this;
}

mString& mString::operator=(char* str)
{
    mainStr = strdup(str);
    return *this;
}

mString& mString::operator=(const char* str)
{
    mainStr = strdup(str);
    return *this;
}

mString& mString::operator+=(std::string str)
{
    this->mainStr = (char*)(realloc(this->mainStr, strlen(this->mainStr) + str.size() + 1));
    strcat(this->mainStr, str.c_str());
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

char mString::chartAt(int num)
{
    return mainStr[num];
}

int mString::length()
{
    return strlen(mainStr);
}

mString mString::toUpStr()
{
    unsigned int i = 0;
    while (i < this->length())
    {
        if (mainStr[i] >= 'a' && mainStr[i] <= 'z')
        {
            mainStr[i] = char(mainStr[i] - 32);
        }
        i++;
    }
    return mainStr;
}

mString mString::toLowStr()
{
    unsigned int i = 0;
    while (i < this->length())
    {
        if (mainStr[i] >= 'A' && mainStr[i] <= 'Z')
        {
            mainStr[i] = char(mainStr[i] + 32);
        }
        i++;
    }
    return mainStr;
}
