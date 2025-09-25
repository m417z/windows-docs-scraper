typedef struct _WSANAMESPACE_INFOEXA {
  GUID  NSProviderId;
  DWORD dwNameSpace;
  BOOL  fActive;
  DWORD dwVersion;
  LPSTR lpszIdentifier;
  BLOB  ProviderSpecific;
} WSANAMESPACE_INFOEXA, *PWSANAMESPACE_INFOEXA, *LPWSANAMESPACE_INFOEXA;