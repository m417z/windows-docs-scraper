typedef struct _WSAServiceClassInfoW {
  LPGUID            lpServiceClassId;
  LPWSTR            lpszServiceClassName;
  DWORD             dwCount;
  LPWSANSCLASSINFOW lpClassInfos;
} WSASERVICECLASSINFOW, *PWSASERVICECLASSINFOW, *LPWSASERVICECLASSINFOW;