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
		// �޸𸮸� �Ҵ��Ѵ�
		m_pnData = new int;

		// �����Ͱ� ����Ű�� ��ġ�� ���� �����Ѵ�.
		*m_pnData = *rhs.m_pnData;
	}
	// ��ü�� �Ҹ��ϸ� ���� �Ҵ��� �޸𸮸� �����Ѵ�
	~CMyData() {
		delete m_pnData;
	}
	int GetData() const {
		if (m_pnData != NULL) return *m_pnData;
		return 0;
	}

private:
	// ������ ��� ������
	int* m_pnData = nullptr;
};

int main() {
	CMyData a(10);
	CMyData b(a);
	CMyData c;

	// �ܼ� ������ �õ��ϸ� ��� ����� ���� �״�� �����Ѵ� (shallow copy)
	c = b;
	
	cout << a.GetData() << endl;
	cout << b.GetData() << endl;
	cout << c.GetData() << endl;

	return 0;
}