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
    if(num < this->sizeStr) 
        return mainStr[num];
    return ' ';
}

int mString::length()
{
    return sizeStr;
}

char* mString::getTextChar()
{
    return mainStr;
}

mString mString::toUpStr()
{
    mString upStr = *this;
    for(size_t i = 0; i < upStr.sizeStr; i++)
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
    for (size_t i = 0; i < lowStr.sizeStr; i++) 
    {
        if (lowStr.mainStr[i] >= 'A' && lowStr.mainStr[i] <= 'Z')
        {
            lowStr.mainStr[i] = char(lowStr.mainStr[i] + 32);
        }
    }
    return lowStr;
}

bool mString::beginWith(char bChar)
{
    if (mainStr[0] == bChar)
        return true;
    return false;
}

bool mString::endWith(char eChar)
{
    if (mainStr[this->sizeStr - 1] == eChar)
        return true;
    return false;
}

bool mString::includes(char iChar)
{
    for (size_t i = 0; i < this->sizeStr; i++)
    {
        if (mainStr[i] == iChar)
            return true;
    }
    return false;
}

int mString::indexChar(char iChar)
{
    for (size_t i = 0; i < this->sizeStr; i++)
    {
        if (mainStr[i] == iChar)
            return i;
    }
    return 0;
}

int mString::lastIndexChar(char lChar)
{
    for (size_t i = 0; i < this->sizeStr; i++)
    {
        if (mainStr[this->sizeStr - i] == lChar)
            return this->sizeStr - i;
    }
    return 0;
}

size_t mString::searchCount(char sChar)
{
    size_t countChar = 0;
    for (size_t i = 0; i < this->sizeStr; i++)
    {
        if (mainStr[i] == sChar)
            countChar++;
    }
    return countChar;

}
