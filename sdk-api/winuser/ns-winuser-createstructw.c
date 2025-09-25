typedef struct tagCREATESTRUCTW {
  LPVOID    lpCreateParams;
  HINSTANCE hInstance;
  HMENU     hMenu;
  HWND      hwndParent;
  int       cy;
  int       cx;
  int       y;
  int       x;
  LONG      style;
  LPCWSTR   lpszName;
  LPCWSTR   lpszClass;
  DWORD     dwExStyle;
} CREATESTRUCTW, *LPCREATESTRUCTW;