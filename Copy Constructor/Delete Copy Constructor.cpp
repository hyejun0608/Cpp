#include <iostream>
using namespace std;

class CTestData {
public:
	CTestData(int nParam) : m_nData(nParam) { cout << "CTestData(int)" << endl; }

	// ���� �����ڸ� �ƿ� ���������ν� ���� ������ ���´�
	CTestData(const CTestData& rhs) = delete;
	// �б� ������ ����� �޼���
	int GetData() const { return m_nData; }

	// ��� ������ ���⸦ �õ��ϴ� �޼���
	void SetData(int nParam) { m_nData = nParam; }

private:
	int m_nData = 0;
};

void TestFunc(CTestData param) {
	cout << "TestFunc()" << endl;

	// ��ȣ���� �Լ����� �Ű����� �ν��Ͻ��� ���� �����Ѵ�.
	param.SetData(20);
}

int main() {
	cout << "**** Begin ****" << endl;

	// ����� �ڵ忡�� ���� ������ �Ұ����ϴ�.
	CTestData a(10);
	TestFunc(a);

	// �Լ� ȣ�� �� a�� ���� ����Ѵ�.
	cout << "a : " << a.GetData() << endl;

	cout << "**** End ****" << endl;
	return 0;
}