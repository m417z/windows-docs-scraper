typedef struct _ICONINFOEXW {
  DWORD   cbSize;
  BOOL    fIcon;
  DWORD   xHotspot;
  DWORD   yHotspot;
  HBITMAP hbmMask;
  HBITMAP hbmColor;
  WORD    wResID;
  WCHAR   szModName[MAX_PATH];
  WCHAR   szResName[MAX_PATH];
} ICONINFOEXW, *PICONINFOEXW;