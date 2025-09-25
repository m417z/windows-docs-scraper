typedef struct _PubAppInfo {
  DWORD      cbSize;
  DWORD      dwMask;
  LPWSTR     pszSource;
  SYSTEMTIME stAssigned;
  SYSTEMTIME stPublished;
  SYSTEMTIME stScheduled;
  SYSTEMTIME stExpire;
} PUBAPPINFO, *PPUBAPPINFO;