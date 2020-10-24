#pragma once
class CMyString {
private:
	// 문자열을 저장하기 위해 동적 할당한 메모리를 가리키는 포인터
	char* m_pszData;
	// 저장된 문자열의 길이
	int m_nLength;
public:
	CMyString();
	~CMyString();
	// 변환 생성자
	explicit CMyString(const char* pszParam);

	// 복사 생성자
	CMyString(const CMyString& rhs);

	// 이동생성자
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