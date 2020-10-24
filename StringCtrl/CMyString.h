#pragma once
class CMyString {
private:
	// ���ڿ��� �����ϱ� ���� ���� �Ҵ��� �޸𸮸� ����Ű�� ������
	char* m_pszData;
	// ����� ���ڿ��� ����
	int m_nLength;
public:
	CMyString();
	~CMyString();
	// ��ȯ ������
	explicit CMyString(const char* pszParam);

	// ���� ������
	CMyString(const CMyString& rhs);

	// �̵�������
	CMyString(CMyString&& rhs);

	int GetLength() const;

	char& operator[](int nIndex);
	char operator[](int nIndex) const;

	int operator==(const CMyString& rhs);
	int operator!=(const CMyString& rhs);

	CMyString operator+(const CMyString& rhs);
	CMyString& operator+=(const CMyString& rhs);
	CMyString& operator = (const CMyString& rhs);

	int SetString(const char* pszParam);
	const char* GetString() const;
	void Release();
	int Append(const char* pszParam);
	operator char* () const {
		return	m_pszData;
	}
};