typedef struct tagTOOLINFOA {
  UINT      cbSize;
  UINT      uFlags;
  HWND      hwnd;
  UINT_PTR  uId;
  RECT      rect;
  HINSTANCE hinst;
  LPSTR     lpszText;
  LPARAM    lParam;
  void      *lpReserved;
} TTTOOLINFOA, *PTOOLINFOA, *LPTTTOOLINFOA;