typedef struct _WSANAMESPACE_INFOW {
  GUID   NSProviderId;
  DWORD  dwNameSpace;
  BOOL   fActive;
  DWORD  dwVersion;
  LPWSTR lpszIdentifier;
} WSANAMESPACE_INFOW, *PWSANAMESPACE_INFOW, *LPWSANAMESPACE_INFOW;