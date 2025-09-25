typedef struct tagMENUBARINFO {
  DWORD cbSize;
  RECT  rcBar;
  HMENU hMenu;
  HWND  hwndMenu;
  BOOL  fBarFocused : 1;
  BOOL  fFocused : 1;
  BOOL  fUnused : 30;
} MENUBARINFO, *PMENUBARINFO, *LPMENUBARINFO;