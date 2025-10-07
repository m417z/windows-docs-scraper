typedef struct tagReaderModeInfo {
  UINT                       cbSize;
  HWND                       hwnd;
  DWORD                      fFlags;
  LPRECT                     prc;
  PFNREADERSCROLL            pfnScroll;
  PFNREADERTRANSLATEDISPATCH fFlags;
  LPARAM                     lParam;
} READERMODEINFO, *PREADERMODEINFO;