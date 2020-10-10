#include <iostream>
using namespace std;

class CTestData {
public:
	// �Ű������� �ϳ����� �����ڴ� ����ȯ�� �����ϴ�
	CTestData(int nParam) : m_nData(nParam) {
		cout << "CTestData(int)" << endl;
	}
	CTestData(const CTestData& rhs) : m_nData(rhs.m_nData) {
		cout << "CTestData(const CTestData &)" << endl;
	}
	int GetData() const { return m_nData; }
	void SetData(int nParam) { m_nData = nParam; }
private:
	int m_nData;
};

// �Ű������� Ŭ���� �����̸� ��ȯ ������ �����ϴ�
void TestFunc(CTestData param) {
	cout << "TestFunc(): " << param.GetData() << endl;
}
int main() {
	// int �ڷ������� CTestData ������ ��ȯ�� �� �ִ�
	TestFunc(5);

	return 0;
}