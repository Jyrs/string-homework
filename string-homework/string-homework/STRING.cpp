#include<iostream>
#include "STRING.h"

using namespace std;


STRING::STRING()		//конструктор без параметров
{
	size = rand() % 15;
	char temp = ' ';
	for (int i = 0; i < size; i++)
	{
		temp = rand() % 101;
		str.emplace_back(temp);
	}
}
STRING::STRING(const char n[]) //констурктор с параметрами
{	
	int i = 0;
	while (n[i] != '\0')
	{
		str.emplace_back(n[i]);
		i++;
	}
	size = i;

}
STRING::STRING(const STRING& stri) // конструктор копирования
{
	size = stri.size;
	str = stri.str;
}
STRING::STRING(vector<char> str1)
{
	size = str1.size();
	str = str1;

}

STRING::~STRING()
{
	str.clear();
	str.shrink_to_fit();
}
STRING& STRING::operator=(STRING const& strr)
{
	str.clear();
	str.shrink_to_fit();
	size = strr.size;
	for (char element : strr.str)
		str.emplace_back(element);
	return *this;
}

STRING STRING::operator+(STRING const& str1)
{
	vector<char> str3_vec;
	for (int i = 0; i < this->size; i++)
		str3_vec.emplace_back(str[i]);

	for (int i = 0; i < str1.size; i++)
		str3_vec.emplace_back(str1.str[i]);

	return STRING(str3_vec);
}
STRING STRING::operator+=(STRING const& str1)
{
	*this = *this + str1;
	return *this;
}

bool STRING::operator==(STRING const& strR)
{
	if (this->size != strR.size)
		return false;
	else if (this->str == strR.str)
		return true;
	else return false;
}

bool STRING::operator!=(STRING const& strR)
{
	if (this->str != strR.str)
		return true;
	else return false;
}

int STRING::getSize()				// возвращение размера строки
{
		return this->size;
}

void STRING::eraseString()								//очистка строки...
{	
	str.clear();  //...путем очистки вектора
	size = 0;
	str.shrink_to_fit();
}

ostream& operator<<(ostream& out, const STRING& outstr)
{
	for (int i = 0; i < outstr.size; i++)
		out << outstr.str[i];
	return out;
}
