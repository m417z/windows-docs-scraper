typedef struct _cpinfoexW {
  UINT  MaxCharSize;
  BYTE  DefaultChar[MAX_DEFAULTCHAR];
  BYTE  LeadByte[MAX_LEADBYTES];
  WCHAR UnicodeDefaultChar;
  UINT  CodePage;
  WCHAR CodePageName[MAX_PATH];
} CPINFOEXW, *LPCPINFOEXW;