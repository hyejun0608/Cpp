#include <iostream>
using namespace std;

class CMyData {
public:
	CMyData() { cout << "CMyData()" << endl; }

	int GetData() const { return m_nData; }
	void SetData(int nParam) { m_nData = nParam; }

private:
	int m_nData = 0;
};

int main() {
	// ����Ʈ �����ڰ� ȣ��Ǵ� ���
	CMyData a;
	a.SetData(10);

	// ���� �����ڰ� ȣ��Ǵ� ���
	CMyData b(a);
	cout << b.GetData() << endl;

	return 0;
}