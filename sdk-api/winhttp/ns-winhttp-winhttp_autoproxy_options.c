typedef struct _WINHTTP_AUTOPROXY_OPTIONS {
  DWORD   dwFlags;
  DWORD   dwAutoDetectFlags;
  LPCWSTR lpszAutoConfigUrl;
  LPVOID  lpvReserved;
  DWORD   dwReserved;
  BOOL    fAutoLogonIfChallenged;
} WINHTTP_AUTOPROXY_OPTIONS, *PWINHTTP_AUTOPROXY_OPTIONS;