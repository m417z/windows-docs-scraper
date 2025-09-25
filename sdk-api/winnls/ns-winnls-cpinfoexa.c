typedef struct _cpinfoexA {
  UINT  MaxCharSize;
  BYTE  DefaultChar[MAX_DEFAULTCHAR];
  BYTE  LeadByte[MAX_LEADBYTES];
  WCHAR UnicodeDefaultChar;
  UINT  CodePage;
  CHAR  CodePageName[MAX_PATH];
} CPINFOEXA, *LPCPINFOEXA;