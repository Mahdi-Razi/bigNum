#include <iostream>
#include <string>
#include <stdexcept>
#include "bigNum.h"
using namespace std;

bigNum::bigNum(string str)
{
	s = str;
	sign = true;
	if(s[0] == '-'){
		sign = false;
		s.erase(s.begin());
	}
	else if(s[0] == '+'){
		sign = true;
		s.erase(s.begin());
	}
	while(s[0] == '0')
		s.erase(s.begin());
	if(s.length() == 0) s = "0";
}

bigNum::bigNum(int x)
{
	
    (*this) = std::to_string(x);
}

bigNum::bigNum(const char *p)
{
	int i = 0;
	string str;
	while(p[i] != 0){
		str.push_back(p[i]);
		i++;
	}
	
	(*this) = str;
}

bigNum::bigNum(const bigNum &b)
{
	this->s = b.s;
	this->sign=b.sign;
}

istream &operator>>(istream &input, bigNum &a)
{
	string str;
	input >> str;
	a = str;
	return input;
}

ostream &operator<<(ostream &output, const bigNum &a)
{
	if(a.sign == false)
		output << "-";
	cout << a.s;
	return output;
}

bool bigNum::operator>(const bigNum &b)
{
	if(sign && !b.sign) 
		return true;
	if(!sign && b.sign) 
		return false;
	if(s.length() > b.s.length()){
		if(sign && b.sign)
			return true;
		return false;
	}
	if(s.length() < b.s.length()){
		if(sign && b.sign)
			return false;
		return true;
	}
	if(s > b.s){
		if(sign && b.sign)
			return true;
		return false;}
	if(s < b.s){
		if(sign && b.sign)
			return false;
		return true;
	}
	return false;
}

bool bigNum::operator>(const long a)
{
    bigNum tmp;
    tmp = a;
    return *this > tmp;
}

bool bigNum::operator<(const bigNum &b)
{
	if(sign && !b.sign)
		return false;
	if(!sign && b.sign)
		return true;
	if(s.length() > b.s.length()){
		if(sign && b.sign)
			return false;
		return true;
	}
	if(s.length() < b.s.length()){
		if(sign && b.sign)
			return true;
		return false;
	}
	if(s > b.s){
		if(sign && b.sign) 
			return false;
		return true;
	}
	if(s < b.s){
		if(sign && b.sign)
			return true;
		return false;
	}
	return false;
}

bool bigNum::operator<(const long a)
{
    bigNum tmp;
    tmp = a;
    return *this < tmp;
}

bool bigNum::operator>=(const bigNum &b)
{
	if((*this) > b)
		return true;
	if((*this) < b)
		return false;
	return true;
}

bool bigNum::operator>=(const long a)
{
    bigNum tmp;
    tmp = a;
    return *this >= tmp;
}

bool bigNum::operator<=(const bigNum &b)
{
	if((*this) < b)
		return true;
	if((*this) > b)
		return false;
	return true;
}

bool bigNum::operator<=(const long a)
{
    bigNum tmp;
    tmp = a;
    return *this <= tmp;
}

bool bigNum::operator==(const bigNum &b)
{
	return (sign == b.sign && s == b.s);
}

bool bigNum::operator==(const long a)
{
    bigNum tmp;
    tmp = a;
    return *this == tmp;
}

int bigNum::operator[](int index)
{
	if(index < 1 || index > s.length())
		throw out_of_range("INDEX IS OUT OF RANGE!");
	else
		return (s[index - 1] - '0');
}

void bigNum::printDelimiter()
{
	if(sign == false)
		cout << "-";
	int i;
	if(s.length() % 3 == 0) i = 0;
	else if(s.length() % 3 == 1) i = 2;
	else i = 1;

	for(int j = 0; j < s.length(); j++){
		if(!(i % 3) && j) cout << ',';
		cout << s[j];
		i++;
	}
	cout << endl;
}

bigNum bigNum::operator+(const bigNum &b)
{
	bigNum tmp, tmp1, tmp2;
	tmp1 = *this;
	tmp2 = b;
	tmp1.sign = 1;
	tmp2.sign = 1;
	if(sign && !b.sign) { 
		tmp =  tmp1 - tmp2;
		if(comp((*this), b) == 1)
			tmp.sign = true;
		else
			tmp.sign = false;
		return tmp;
	}
	if(!sign && b.sign){
		tmp =  tmp1 - tmp2;
		if(comp((*this), b) == 1)
			tmp.sign = false;
		else
			tmp.sign = true;
		return tmp;
	}
	
	int sum = 0;
	int carry = 0;
	int i;

	tmp1.s = string(tmp1.s.rbegin(),tmp1.s.rend());
	tmp2.s = string(tmp2.s.rbegin(),tmp2.s.rend());

	for(i = 0; i < min(s.length(), b.s.length()); i++)
	{
		sum = (tmp1.s[i] - '0') + (tmp2.s[i] - '0') + carry;
		tmp.s.push_back(char(sum % 10 + '0'));
		carry = sum / 10;
	}

	for(; i < max(s.length(), b.s.length()); i++)
	{
		if(s.length() > b.s.length())
			sum = (tmp1.s[i] - '0') + carry;
		else
			sum = (tmp2.s[i] - '0') + carry;
		tmp.s.push_back(char(sum % 10 + '0'));
		carry = sum / 10;
	}
	if(carry)
		tmp.s.push_back(char(carry + '0'));	
	
	tmp.s = string(tmp.s.rbegin(),tmp.s.rend());

	if(sign && b.sign)
		tmp.sign = true;
	if(!sign && !b.sign)
		tmp.sign = false;
	
	return tmp;	
}

bigNum bigNum::operator+(const long a)
{
    bigNum tmp;
    tmp = a;
    return *this + tmp;
}

bigNum bigNum::operator-(const bigNum &b)
{	
	bigNum tmp, tmp1, tmp2;
	tmp1 = *this;
	tmp2 = b;
	tmp1.sign = 1;
	tmp2.sign = 1;
	if(sign && !b.sign) { 
		tmp =  tmp1 + tmp2;
		tmp.sign = true;
		return tmp;
	}
	if(!sign && b.sign){
		tmp =  tmp1 + tmp2;
		tmp.sign = false;
		return tmp;
	}
	int dif = 0;
	int carry = 0;
	int i;

	tmp1.s = string(tmp1.s.rbegin(),tmp1.s.rend());
	tmp2.s = string(tmp2.s.rbegin(),tmp2.s.rend());

	for(i = 0; i < min(s.length(), b.s.length()); i++)
	{
		if(comp(*this , b))
			dif = (tmp1.s[i] - '0') - (tmp2.s[i] - '0') - carry;
		else
			dif = (tmp2.s[i] - '0') - (tmp1.s[i] - '0') - carry;
		if(dif < 0){
			dif += 10;
			carry = 1;
		}
		else
			carry = 0;

		tmp.s.push_back(char(dif + '0'));
	}

	for(; i < max(s.length(), b.s.length()); i++)
	{
		if(s.length() > b.s.length())
			dif = (tmp1.s[i] - '0') - carry;
		else
			dif = (tmp2.s[i] - '0') - carry;

		if(dif < 0){
			dif += 10;
			carry = 1;
		}
		else
			carry = 0;

		tmp.s.push_back(char(dif + '0'));
	}

	tmp.s = string(tmp.s.rbegin(),tmp.s.rend());

	while(tmp.s[0] == '0')
		tmp.s.erase(tmp.s.begin());
	if(tmp.s.length() == 0) tmp.s = "0";

	if(sign && b.sign){
		if(comp((*this), b))
			tmp.sign = true;
		else
			tmp.sign = false;
	}
	if(!sign && !b.sign){
		if(comp((*this), b))
			tmp.sign = false;
		else
			tmp.sign = true;
	}

	return tmp;
}

bigNum bigNum::operator-(const long a)
{
    bigNum tmp;
    tmp = a;
    return *this - tmp;
}

bigNum bigNum::operator*(const bigNum &b)
{
	bigNum *tmp = new bigNum[s.length()];
	bigNum m = 0;
	int mul = 0;
	int carry = 0;

	bigNum tmp1 = *this;
	bigNum tmp2 = b;
	tmp1.s = string(tmp1.s.rbegin(),tmp1.s.rend());
	tmp2.s = string(tmp2.s.rbegin(),tmp2.s.rend());
	
	for(int i = 0; i < s.length(); i++){

		carry = 0;
		for(int k = 0; k < i; k++)
				tmp[i].s.push_back('0');

		for(int j = 0; j < b.s.length(); j++){
			mul = (tmp1.s[i] - '0') * (tmp2.s[j] - '0') + carry;
			tmp[i].s.push_back(char(mul % 10 + '0'));
			carry = mul / 10;
		}
		if(carry)
			tmp[i].s.push_back(char(carry + '0'));

		tmp[i].s = string(tmp[i].s.rbegin(),tmp[i].s.rend());
		while(tmp[i].s[0] == '0')
			tmp[i].s.erase(tmp[i].s.begin());
		if(tmp[i].s.length() == 0) tmp[i].s = "0";
		
		m = m + tmp[i];
	}
	if(sign && b.sign || !sign && !b.sign)
		m.sign = true;
	else
		m.sign = false;

	return m;
}

bigNum bigNum::operator*(const long a)
{
    bigNum tmp;
    tmp = a;
    return (*this) * tmp;
}

bool bigNum::comp(const bigNum &a, const bigNum &b)
{
    if(a.s.length() > b.s.length()) return 1;
    if(a.s.length() < b.s.length()) return 0;
    if(a.s > b.s) return 1;
    if(a.s < b.s) return 0;
    return 1;
}