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
	~CTestData() { //�Ҹ��� �߰�
		cout << "~CTestData()" << endl;
	}
	int GetData() const { return m_nData; }
	void SetData(int nParam) { m_nData = nParam; }
private:
	int m_nData;
};

// �Ű������� Ŭ������ ���� ���� �����̸� ���������� ��ȯ �����ȴ�
void TestFunc(CTestData param) {
	cout << "TestFunc(): " << param.GetData() << endl;
}
int main() {
	cout << "****Begin****" << endl;
	// ���ο� CTestData ��ü�� �����ϰ� ������ �����Ѵ�.
	TestFunc(5);
	// �Լ��� ��ȯ�Ǹ鼭 �ӽ� ��ü�� �Ҹ��Ѵ�.
	cout << "****End****" << endl;
	return 0;
}