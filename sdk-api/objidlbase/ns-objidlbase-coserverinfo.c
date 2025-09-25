typedef struct _COSERVERINFO {
  DWORD      dwReserved1;
  LPWSTR     pwszName;
  COAUTHINFO *pAuthInfo;
  DWORD      dwReserved2;
} COSERVERINFO;