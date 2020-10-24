#include <iostream>
#include "CMyString.h"
using namespace std;

int main() {
	CMyString strParam("StudentID: 1107"), strName("Name: 김혜준");

	if (strParam == strName) {
		cout << "같다!" << endl;
	}
	else {
		cout << "다르다!" << endl;
	}
	CMyString strTest = CMyString("StudentID: 1107");

	if (strParam != strTest) {
		cout << "다르다!" << endl;
	}
	else {
		cout << "같다!" << endl;
	}

	return 0;
}