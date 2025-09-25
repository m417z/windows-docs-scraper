typedef struct _SHSTOCKICONINFO {
  DWORD cbSize;
  HICON hIcon;
  int   iSysImageIndex;
  int   iIcon;
  WCHAR szPath[MAX_PATH];
} SHSTOCKICONINFO;