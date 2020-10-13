#include <iostream>
using namespace std;

class CTestData {
public:
	// 매개변수가 하나뿐인 생성자는 형변환이 가능하다
	CTestData(int nParam) : m_nData(nParam) {
		cout << "CTestData(int)" << endl;
	}
	CTestData(const CTestData& rhs) : m_nData(rhs.m_nData) {
		cout << "CTestData(const CTestData &)" << endl;
	}
	~CTestData() { //소멸자 추가
		cout << "~CTestData()" << endl;
	}
	int GetData() const { return m_nData; }
	void SetData(int nParam) { m_nData = nParam; }
private:
	int m_nData;
};

// 매개변수가 클래스에 대한 참조 형식이며 묵시적으로 변환 생성된다
void TestFunc(CTestData param) {
	cout << "TestFunc(): " << param.GetData() << endl;
}
int main() {
	cout << "****Begin****" << endl;
	// 새로운 CTestData 객체를 생성하고 참조로 전달한다.
	TestFunc(5);
	// 함수가 반환되면서 임시 객체는 소멸한다.
	cout << "****End****" << endl;
	return 0;
}