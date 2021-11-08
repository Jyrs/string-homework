#include <string>
#include<iostream>
#include "BitSTRING.h"


using namespace std;

BitSTRING::BitSTRING()
{
	size = rand() % 2;
	char digit;
	for (int i = 0; i < size; i++)
	{
		digit = rand() % 2;
		str.emplace_back(digit);
	}
}

BitSTRING::BitSTRING(const char n[])
{
	str.clear();
	int i = 0;
	while (n[i] != '\0')
	{
		str.emplace_back(n[i]);
		i++;
	}
	size = i;
}

BitSTRING::BitSTRING(const BitSTRING& stri) 
{
	size = stri.size;
	str = stri.str;
}

BitSTRING::BitSTRING(vector<char> str1)
{
	size = str1.size();
	str = str1;

}

BitSTRING::~BitSTRING(){
	str.clear();		 // очищаем вектор
	str.shrink_to_fit();  // удаляем выделенную ненужную память
}



BitSTRING& BitSTRING::operator=(const BitSTRING& strr)
{
	str.clear(); // очищаем вектор от предыдущих значений
	str.shrink_to_fit(); // удаляем память тоже
	size = strr.size;
	for (char element : strr.str)
		str.emplace_back(element);
	return *this;
}

BitSTRING BitSTRING::operator+(BitSTRING const& str1)
{
	vector<char> strSum;  // вектор для готовой суммы

	// нужно добавить незначащие нули в начале числа с меньшим количеством разрядов. Чтобы сравнять разряды двух чисел

	// будет врем. вектор, чтобы не изменять исходные данные т.е. не добавлять незнач. нули в исходную строку
	//

	vector<char> tempVec; 
	int tempVecSize;

	if (this->size != str1.size)
	{
		if (this->size > str1.size) // tempVec принимет вектор левого или правого операнда
		{
			tempVec = str1.str;
			tempVecSize = tempVec.size();

			for (int i = tempVecSize; i < this->size; i++)
			{
				tempVec.insert(tempVec.begin(), 0);
				tempVecSize++;
			}
		}
		else
		{
			tempVec = this->str;
			tempVecSize = tempVec.size();

			for (int i = tempVecSize; i < str1.size; i++)
			{
				tempVec.insert(tempVec.begin(), 0);
				tempVecSize++;
			}
		}

	}

	if (this->size == str1.size)
	{
		int tempNextDigitFlag = 0;   // переменная для запоминания единицы для след. разряда 
		for (int i = str1.size-1; i >= 0; i--)
		{
			if (str1.str[i] == '1' && this->str[i] == '1')
			{
				if (tempNextDigitFlag == 1) strSum.insert(strSum.begin(), '1');
				 else strSum.insert(strSum.begin(), '0');

				tempNextDigitFlag = 1;
			}
			else if (str1.str[i] == '1' || this->str[i] == '1')
			{
				if (tempNextDigitFlag == 1)
				{
					strSum.insert(strSum.begin(), '0');
					tempNextDigitFlag = 1;
				}

				else strSum.insert(strSum.begin(), '1');
			}
			else
			{
				if (tempNextDigitFlag == 1)
				{
					strSum.insert(strSum.begin(), '1');
					tempNextDigitFlag = 0;
				}
				else strSum.insert(strSum.begin(), '0');
			}
		}
	}

	return BitSTRING(strSum);
}

BitSTRING BitSTRING::operator+=(BitSTRING const& str1)
{
	*this = *this + str1;
	return *this;
}

bool BitSTRING::operator==(BitSTRING const& strR)
{
	unsigned int inDecimal1, inDecimal2;

	inDecimal1 = convertToDecimal(*this);
	inDecimal2 = convertToDecimal(strR);

	if(inDecimal1 == inDecimal2)
	return true;
	else return false;
}

bool BitSTRING::operator!=(BitSTRING const& strR)
{
	unsigned int inDecimal1, inDecimal2;

	inDecimal1 = convertToDecimal(*this);
	inDecimal2 = convertToDecimal(strR);

	if (inDecimal1 != inDecimal2) return true; 
	else return false;
}

unsigned int BitSTRING::convertToDecimal(BitSTRING const& stroka)
{
	unsigned int sum = 0;
	for (int i = 0; i < stroka.size; i++)
		if (stroka.str[i] == '0') continue;
		else sum += pow(2, i);
	return sum;
}


ostream& operator<<(ostream& out, const BitSTRING& outstr)
{
	for (int i = 0; i < outstr.size; i++)
		out << outstr.str[i];
	return out;
}