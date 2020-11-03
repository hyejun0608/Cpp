#include <iostream>
#include "CMyString.h"
#include "CMyStringEx.h"
using namespace std;

int main() {
	CMyStringEx strTest;
	strTest.SetString("학번: 1107, 이름: 김혜준");
	cout << strTest << endl;

	int nIndex = strTest.Find("김혜준");
	cout << "Index: " << nIndex << endl;

	return 0;
}