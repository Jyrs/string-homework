#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "STRING.h"
#include "BitSTRING.h"

using namespace std;

int main() {

	setlocale(LC_ALL, "rus");
	STRING stroka1("324234");
	STRING stroka2("HelloWorld!");


	cout << "Stroka1: " << stroka1 << endl;
	cout << "Stroka2: " << stroka2 << endl;
	cout << "Stroka 1 + Stroka2: " << stroka1 + stroka2 << endl;
	stroka1 += stroka2;
	cout << "Stroka 1 += Stroka2: " << stroka1 << endl;

	STRING stroka3 = stroka1;

	if (stroka1 == stroka2) cout << "equal" << endl; else cout << " not equal" << endl;

	if (stroka1 == stroka3) cout << "equal" << endl; else cout << " not equal" << endl;


	BitSTRING bitstroka1("1010110");
	BitSTRING bitstroka2("110");
	BitSTRING bitstroka3;

	cout << "Bitstroka1: " << bitstroka1 << endl;
	cout << "Bitstroka2: " << bitstroka2 << endl;
	cout << "Bitstroka1 + Bitstroka2: " << bitstroka1 + bitstroka2 << endl;

	bitstroka3 = bitstroka2;
	cout << "Bitstroka3: " << bitstroka3 << endl;

	if(bitstroka1 != bitstroka2)
		cout << "not equal" << endl; else cout << " equal" << endl;

	if (bitstroka2 == bitstroka3)
		cout << "equal" << endl; else cout << "not equal" << endl;






}