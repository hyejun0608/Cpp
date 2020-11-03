#include "CMyStringEx.h"
#include <string.h>


int CMyStringEx::Find(const char* pszParam) {
    const char* ptr = strstr(GetString(), pszParam);
    if (ptr == NULL) {
        return -1;
    }
    else {
        return(ptr - GetString());
    }
}