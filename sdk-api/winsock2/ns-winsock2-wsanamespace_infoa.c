typedef struct _WSANAMESPACE_INFOA {
  GUID  NSProviderId;
  DWORD dwNameSpace;
  BOOL  fActive;
  DWORD dwVersion;
  LPSTR lpszIdentifier;
} WSANAMESPACE_INFOA, *PWSANAMESPACE_INFOA, *LPWSANAMESPACE_INFOA;