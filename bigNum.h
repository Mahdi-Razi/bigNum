#ifndef BIGNUM_H_INCLUDED
#define BIGNUM_H_INCLUDED

#include <string.h>

class bigNum{
    friend std::ostream &operator<<(std::ostream&, const bigNum&);
    friend std::istream &operator>>(std::istream&, bigNum&);
public:
    bigNum() : s(""), sign(true) { }
    bigNum(std::string);
    bigNum(int);
    bigNum(const char *);
    bigNum(const bigNum&);

    bool operator>(const bigNum&);
    bool operator>(const long);

    bool operator<(const bigNum&);
    bool operator<(const long);

    bool operator>=(const bigNum&);
    bool operator>=(const long);

    bool operator<=(const bigNum&);
    bool operator<=(const long);

    bool operator==(const bigNum&);
    bool operator==(const long);

    bool operator!=(const bigNum &b) {return !(*this == b);}
    bool operator!=(const long a) {return !(*this == a);}

    int operator[](int);
    
    void printDelimiter();

    bigNum operator+(const bigNum&);
    bigNum operator+(const long);
    
    bigNum operator-(const bigNum&);
    bigNum operator-(const long);
    
    bigNum operator*(const bigNum&);
    bigNum operator*(const long);

    bigNum operator+=(const bigNum &b) {return *this = *this + b;}
    bigNum operator+=(const long a) {return *this = *this + a;}

    bigNum operator-=(const bigNum &b) {return *this = *this - b;}
    bigNum operator-=(const long a) {return *this = *this - a;}

    bigNum operator*=(const bigNum &b) {return *this = (*this) * b;}
    bigNum operator*=(const long a) {return *this = (*this) * a;}

private:
    std::string s;
    bool sign;
    bool comp(const bigNum&, const bigNum&);
};
#endif