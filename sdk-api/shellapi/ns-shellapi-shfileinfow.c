typedef struct _SHFILEINFOW {
  HICON hIcon;
  int   iIcon;
  DWORD dwAttributes;
  WCHAR szDisplayName[MAX_PATH];
  WCHAR szTypeName[80];
} SHFILEINFOW;