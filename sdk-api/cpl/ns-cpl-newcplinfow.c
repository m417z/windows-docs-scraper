typedef struct tagNEWCPLINFOW {
  DWORD    dwSize;
  DWORD    dwFlags;
  DWORD    dwHelpContext;
  LONG_PTR lData;
  HICON    hIcon;
  WCHAR    szName[32];
  WCHAR    szInfo[64];
  WCHAR    szHelpFile[128];
} NEWCPLINFOW, *LPNEWCPLINFOW;