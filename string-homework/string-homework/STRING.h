#include <string>
#include <memory>
#include <vector>
#pragma once


using namespace std;

class STRING
{
protected:
	vector<char> str;
	int size;

public: 
	
	STRING();
	STRING(const char[]);
	STRING(const STRING&); //конструктор копирования
	STRING(vector<char>);
	virtual ~STRING();

	STRING& operator=(STRING const&);
	STRING operator+(STRING const& str1);
	STRING operator+=(STRING const& str1);
	bool operator==(STRING const& strR);
	bool operator!=(STRING const& strR);

	friend ostream& operator<<(ostream&, const STRING&);

	int getSize();
	void eraseString();
};

