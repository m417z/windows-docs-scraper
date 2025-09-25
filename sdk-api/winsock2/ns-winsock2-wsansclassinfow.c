typedef struct _WSANSClassInfoW {
  LPWSTR lpszName;
  DWORD  dwNameSpace;
  DWORD  dwValueType;
  DWORD  dwValueSize;
  LPVOID lpValue;
} WSANSCLASSINFOW, *PWSANSCLASSINFOW, *LPWSANSCLASSINFOW;