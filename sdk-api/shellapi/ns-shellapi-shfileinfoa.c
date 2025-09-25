typedef struct _SHFILEINFOA {
  HICON hIcon;
  int   iIcon;
  DWORD dwAttributes;
  CHAR  szDisplayName[MAX_PATH];
  CHAR  szTypeName[80];
} SHFILEINFOA;