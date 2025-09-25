typedef struct _gettextex {
  DWORD  cb;
  DWORD  flags;
  UINT   codepage;
  LPCSTR lpDefaultChar;
  LPBOOL lpUsedDefChar;
} GETTEXTEX;