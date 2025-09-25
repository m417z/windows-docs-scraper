typedef struct _WSAServiceClassInfoA {
  LPGUID            lpServiceClassId;
  LPSTR             lpszServiceClassName;
  DWORD             dwCount;
  LPWSANSCLASSINFOA lpClassInfos;
} WSASERVICECLASSINFOA, *PWSASERVICECLASSINFOA, *LPWSASERVICECLASSINFOA;