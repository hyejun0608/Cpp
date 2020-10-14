#include "CMyString.h"
#include <iostream>
#include <string.h>
using namespace std;
#pragma warning(disable:4996)

CMyString::CMyString()
	:m_pszData(nullptr)
	, m_nLength(0) {
}

CMyString::CMyString(const	char* pszParam)
	: m_pszData(nullptr)
	, m_nLength(0) {
	SetString(pszParam);
}

CMyString::CMyString(CMyString&& rhs)
	:m_pszData(nullptr)
	, m_nLength(0) {
	cout << "CMyString 이동생성자 호출" << endl;

	// 얕은 복사를 수행해도 상관없다. 어차피 원본이 곧 소멸됨
	m_pszData = rhs.m_pszData;
	m_nLength = rhs.m_nLength;

	// 원본 임시 객체의 멤버들은 초기화 한다. 절대로 해제하면 안된다
	rhs.m_pszData = nullptr;
	rhs.m_nLength = 0;
}

CMyString::CMyString(const CMyString& rhs) {
	m_nLength = rhs.m_nLength;
	m_pszData = new char[m_nLength + 1];
	strcpy(m_pszData, rhs.m_pszData);
}

CMyString& CMyString::operator=(const CMyString& rhs) {
	m_nLength = rhs.m_nLength;
	if (m_pszData != NULL) {
		delete[] m_pszData;
	}
	m_pszData = new char[m_nLength + 1];
	strcpy(m_pszData, rhs.m_pszData);
	return *this;
}

CMyString::~CMyString() {
	Release();
}


int CMyString::SetString(const char* pszParam) {
	m_nLength = strlen(pszParam);
	if (pszParam == nullptr || m_nLength <= 0)
	{
		return 0;
	}
	if (m_pszData != nullptr)
	{
		Release();
	}
	m_pszData = new char[m_nLength + 1];
	strcpy(m_pszData, pszParam);

	return 0;
}

const char* CMyString::GetString() const {
	if (m_nLength == 0)
		return "";
	return m_pszData;
}

void CMyString::Release() {
	if (m_pszData != nullptr)
		delete[] m_pszData;
	m_pszData = nullptr;
}