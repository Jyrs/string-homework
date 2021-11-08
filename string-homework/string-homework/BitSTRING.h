#pragma once
#include "STRING.h"
#include "math.h"

class BitSTRING :
    public STRING
{
public:
	BitSTRING();
	BitSTRING(const char[]);
	BitSTRING(const BitSTRING&);
	BitSTRING(vector<char> str1);
	~BitSTRING();

	BitSTRING& operator=(const BitSTRING&);
	BitSTRING operator+(BitSTRING const& str1);
	BitSTRING operator+=(BitSTRING const& str1);
	bool operator==(BitSTRING const& strR);
	bool operator!=(BitSTRING const& strR);

	friend ostream& operator<<(ostream&, const BitSTRING&);
 
private:
	unsigned int convertToDecimal(BitSTRING const& stroka);


};

