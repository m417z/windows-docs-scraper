typedef struct tagMDICREATESTRUCTW {
  LPCWSTR szClass;
  LPCWSTR szTitle;
  HANDLE  hOwner;
  int     x;
  int     y;
  int     cx;
  int     cy;
  DWORD   style;
  LPARAM  lParam;
} MDICREATESTRUCTW, *LPMDICREATESTRUCTW;