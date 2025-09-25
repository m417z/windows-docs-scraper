typedef struct _COMMCONFIG {
  DWORD dwSize;
  WORD  wVersion;
  WORD  wReserved;
  DCB   dcb;
  DWORD dwProviderSubType;
  DWORD dwProviderOffset;
  DWORD dwProviderSize;
  WCHAR wcProviderData[1];
} COMMCONFIG, *LPCOMMCONFIG;