typedef struct tagNEWCPLINFOA {
  DWORD    dwSize;
  DWORD    dwFlags;
  DWORD    dwHelpContext;
  LONG_PTR lData;
  HICON    hIcon;
  CHAR     szName[32];
  CHAR     szInfo[64];
  CHAR     szHelpFile[128];
} NEWCPLINFOA, *LPNEWCPLINFOA;