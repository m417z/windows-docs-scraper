typedef struct _WSANAMESPACE_INFOEXW {
  GUID   NSProviderId;
  DWORD  dwNameSpace;
  BOOL   fActive;
  DWORD  dwVersion;
  LPWSTR lpszIdentifier;
  BLOB   ProviderSpecific;
} WSANAMESPACE_INFOEXW, *PWSANAMESPACE_INFOEXW, *LPWSANAMESPACE_INFOEXW;