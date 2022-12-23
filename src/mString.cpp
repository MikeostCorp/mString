#include "mString.h"

//===========================================
//
// Implementing class methods
//
//===========================================

mString::mString()
{
}

mString::mString(std::string str)
{
    mainStr = strdup(str.c_str());
    sizeStr = str.size();
}

mString::mString(mString* str)
{
    mainStr = strdup(str->mainStr);
    sizeStr = str->sizeStr;
}

mString::mString(char* str)
{
    mainStr = strdup(str);
    sizeStr = strlen(str);
}

mString::mString(const char* str)
{
    mainStr = strdup(str);
    sizeStr = strlen(str);
}

mString::~mString()
{
    if(!mainStr) free(mainStr);
}

mString& mString::operator=(std::string str)
{
    mainStr = strdup(str.c_str());
    sizeStr = str.size();
    return *this;
}

mString& mString::operator=(mString str)
{
    mainStr = strdup(str.getText());
    sizeStr = str.length();
    return *this;
}

mString& mString::operator=(char* str)
{
    mainStr = strdup(str);
    sizeStr = strlen(str);
    return *this;
}

mString& mString::operator=(const char* str)
{
    mainStr = strdup(str);
    sizeStr = strlen(str);
    return *this;
}

mString& mString::operator+=(std::string str)
{
    sizeStr += str.size();
    this->mainStr = (char*)(realloc(this->mainStr, sizeStr + 1));
    strcat(this->mainStr, str.c_str());
    return *this;
}

mString& mString::operator+=(mString str)
{
    sizeStr += str.length();
    this->mainStr = (char*)(realloc(this->mainStr, sizeStr + 1));
    strcat(this->mainStr, str.getText());
    return *this;
}

mString& mString::operator+=(char* str)
{
    sizeStr += strlen(str);
    this->mainStr = (char*)(realloc(this->mainStr, sizeStr + 1));
    strcat(this->mainStr, str);
    return *this;
}

mString& mString::operator+=(const char* str)
{
    sizeStr += strlen(str);
    this->mainStr = (char*)(realloc(this->mainStr, sizeStr + 1));
    strcat(this->mainStr, str);
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
    return sizeStr;
}

char* mString::getText()
{
    return mainStr;
}

mString mString::toUpStr()
{
    size_t i = 0;
    while (i < sizeStr)
    {
        if (mainStr[i] >= 'a' && mainStr[i] <= 'z')
        {
            mainStr[i] = char(mainStr[i] - 32);
        }
        ++i;
    }
    return mainStr;
}

mString mString::toLowStr()
{
    size_t i = 0;
    while (i < sizeStr)
    {
        if (mainStr[i] >= 'A' && mainStr[i] <= 'Z')
        {
            mainStr[i] = char(mainStr[i] + 32);
        }
        ++i;
    }
    return mainStr;
}
