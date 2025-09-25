typedef struct tagTOOLINFOW {
  UINT      cbSize;
  UINT      uFlags;
  HWND      hwnd;
  UINT_PTR  uId;
  RECT      rect;
  HINSTANCE hinst;
  LPWSTR    lpszText;
  LPARAM    lParam;
  void      *lpReserved;
} TTTOOLINFOW, *PTOOLINFOW, *LPTTTOOLINFOW;