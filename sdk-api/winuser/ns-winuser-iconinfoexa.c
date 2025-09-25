typedef struct _ICONINFOEXA {
  DWORD   cbSize;
  BOOL    fIcon;
  DWORD   xHotspot;
  DWORD   yHotspot;
  HBITMAP hbmMask;
  HBITMAP hbmColor;
  WORD    wResID;
  CHAR    szModName[MAX_PATH];
  CHAR    szResName[MAX_PATH];
} ICONINFOEXA, *PICONINFOEXA;