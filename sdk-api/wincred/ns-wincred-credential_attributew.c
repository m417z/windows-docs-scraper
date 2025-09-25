typedef struct _CREDENTIAL_ATTRIBUTEW {
#if ...
  wchar_t *Keyword;
#else
  LPWSTR  Keyword;
#endif
  DWORD   Flags;
  DWORD   ValueSize;
  LPBYTE  Value;
} CREDENTIAL_ATTRIBUTEW, *PCREDENTIAL_ATTRIBUTEW;