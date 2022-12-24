#include "mString.h"

//===========================================
//
// Implementing class methods
//
//===========================================

mString::mString()
{
}

mString::mString(const mString &mStr){
    this->sizeStr = mStr.sizeStr;
    this->mainStr = static_cast<char*>(malloc(this->sizeStr + 1));
    strcpy(this->mainStr, mStr.mainStr);
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
    if(mainStr) free(mainStr);
}

mString& mString::operator=(std::string str)
{
    mainStr = strdup(str.c_str());
    sizeStr = str.size();
    return *this;
}

mString& mString::operator=(mString str)
{
    this->mainStr = static_cast<char*>(malloc(str.sizeStr + 1));
    strcpy(this->mainStr, str.mainStr);
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
    strcat(this->mainStr, str.mainStr);
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
    mString upStr = *this;
    size_t i = 0;
    while (i < upStr.sizeStr)
    {
        if (upStr.mainStr[i] >= 'a' && upStr.mainStr[i] <= 'z')
        {
            upStr.mainStr[i] = char(upStr.mainStr[i] - 32);
        }
        ++i;
    }
    return upStr;
}

mString mString::toLowStr()
{
    mString lowStr = *this;
    size_t i = 0;
    while (i < lowStr.sizeStr)
    {
        if (lowStr.mainStr[i] >= 'A' && lowStr.mainStr[i] <= 'Z')
        {
            lowStr.mainStr[i] = char(lowStr.mainStr[i] + 32);
        }
        ++i;
    }
    return lowStr;
}