#include <iostream>
using namespace std;

class CMyData {
public:
	CMyData() {
		cout << "CMyData()" << endl;
		m_pnData = new int;
		*m_pnData = 0;
	}
	CMyData(int nParam) {
		cout << "CMyData(int) " << endl;
		m_pnData = new int;
		*m_pnData = nParam;
	}
	CMyData(const CMyData& rhs) {
		cout << "CMyData(const CMyData& rhs)" << endl;
		// 메모리를 할당한다
		m_pnData = new int;

		// 포인터가 가르키는 위치에 값을 복사한다.
		*m_pnData = *rhs.m_pnData;
	}
	// 객체가 소멸하면 동적 할당한 메모리를 해제한다
	~CMyData() {
		delete m_pnData;
	}
	int GetData() const {
		if (m_pnData != NULL) return *m_pnData;
		return 0;
	}

private:
	// 포인터 멤버 데이터
	int* m_pnData = nullptr;
};

int main() {
	CMyData a(10);
	CMyData b(a);
	CMyData c;

	// 단순 대입을 시도하면 모든 멤버의 값을 그대로 복사한다 (shallow copy)
	c = b;
	
	cout << a.GetData() << endl;
	cout << b.GetData() << endl;
	cout << c.GetData() << endl;

	return 0;
}