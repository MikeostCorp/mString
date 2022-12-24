#include "mString.h"

//===========================================
//
// Implementing class methods
//
//===========================================

mString::mString()
{
    mainStr = strdup("");
    sizeStr = 0;
}

mString::mString(const mString& mStr) 
{
    this->sizeStr = mStr.sizeStr;
    this->mainStr = static_cast<char*>(malloc(this->sizeStr + 1));
    strcpy(this->mainStr, mStr.mainStr);
}

mString::mString(const std::string str)
{
    mainStr = strdup(str.c_str());
    sizeStr = str.size();
}

mString::mString(const mString* str)
{
    mainStr = strdup(str->mainStr);
    sizeStr = str->sizeStr;
}

mString::mString(const char* str)
{
    mainStr = strdup(str);
    sizeStr = strlen(str);
}

mString::~mString()
{
    free(mainStr);
}

mString& mString::operator=(mString str)
{
    mainStr = strdup(str.getTextChar());
    sizeStr = str.length();
    return *this;
}

mString& mString::operator=(const std::string str)
{
    mainStr = strdup(str.c_str());
    sizeStr = str.size();
    return *this;
}

mString& mString::operator=(const char* str)
{
    mainStr = strdup(str);
    sizeStr = strlen(str);
    return *this;
}

mString& mString::operator+=(mString str)
{
    sizeStr += str.length();
    this->mainStr = (char*)(realloc(this->mainStr, sizeStr + 1));
    strcat(this->mainStr, str.getTextChar());
    return *this;
}

mString& mString::operator+=(const std::string str)
{
    sizeStr += str.size();
    this->mainStr = (char*)(realloc(this->mainStr, sizeStr + 1));
    strcat(this->mainStr, str.c_str());
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

size_t mString::length()
{
    return sizeStr;
}

char mString::chartAt(const size_t num)
{
    if(num < this->sizeStr) 
        return mainStr[num];
    return ' ';
}

char* mString::getTextChar()
{
    return mainStr;
}

mString mString::toUpStr()
{
    mString upStr = *this;
    for(size_t i = 0; i < upStr.sizeStr; ++i)
    {
        if (upStr.mainStr[i] >= 'a' && upStr.mainStr[i] <= 'z')
        {
            upStr.mainStr[i] = char(upStr.mainStr[i] - 32);
        }
    }
    return upStr;
}

mString mString::toLowStr()
{
    mString lowStr = *this;
    for (size_t i = 0; i < lowStr.sizeStr; ++i) 
    {
        if (lowStr.mainStr[i] >= 'A' && lowStr.mainStr[i] <= 'Z')
        {
            lowStr.mainStr[i] = char(lowStr.mainStr[i] + 32);
        }
    }
    return lowStr;
}

bool mString::beginWith(const char bChar)
{
    if (mainStr[0] == bChar)
        return true;
    return false;
}

bool mString::endWith(const char eChar)
{
    if (mainStr[sizeStr - 1] == eChar)
        return true;
    return false;
}

bool mString::includes(const char iChar)
{
    for (size_t i = 0; i < sizeStr; ++i)
    {
        if (mainStr[i] == iChar)
            return true;
    }
    return false;
}

size_t mString::indexChar(const char iChar)
{
    for (size_t i = 0; i < sizeStr; ++i)
    {
        if (mainStr[i] == iChar)
            return i;
    }
    return 0;
}

size_t mString::lastIndexChar(const char lChar)
{
    for (size_t i = sizeStr - 1; i >= 0; --i)
    {
        if (mainStr[i] == lChar)
            return i;
    }
    return 0;
}

size_t mString::searchCount(const char sChar)
{
    size_t countChar = 0;
    for (size_t i = 0; i < sizeStr; ++i)
    {
        if (mainStr[i] == sChar)
            countChar++;
    }
    return countChar;
}
