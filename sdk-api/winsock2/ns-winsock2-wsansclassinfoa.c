typedef struct _WSANSClassInfoA {
  LPSTR  lpszName;
  DWORD  dwNameSpace;
  DWORD  dwValueType;
  DWORD  dwValueSize;
  LPVOID lpValue;
} WSANSCLASSINFOA, *PWSANSCLASSINFOA, *LPWSANSCLASSINFOA;