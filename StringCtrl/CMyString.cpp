#include "CMyString.h"
#include <string.h>

CMyString::CMyString()
	:m_pszData(nullptr),
	m_nLength(0) {
}

CMyString::~CMyString() {
	Release();
}


int CMyString::SetString(const char* pszParam) {
	int m_nLength = strlen(pszParam);
	if (pszParam != NULL) {
		Release();
	}
	if (pszParam == NULL || m_nLength == 0) {
		return 0;
	}
	m_pszData = new char[m_nLength+1];
	strcpy(m_pszData, pszParam);
	return 0;
}

const char* CMyString::GetString() {
	return m_pszData;
}

void CMyString::Release() {
	if (m_pszData == NULL) {
		delete[] m_pszData;
	}
}
