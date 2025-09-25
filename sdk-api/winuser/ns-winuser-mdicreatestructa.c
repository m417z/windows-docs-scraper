typedef struct tagMDICREATESTRUCTA {
  LPCSTR szClass;
  LPCSTR szTitle;
  HANDLE hOwner;
  int    x;
  int    y;
  int    cx;
  int    cy;
  DWORD  style;
  LPARAM lParam;
} MDICREATESTRUCTA, *LPMDICREATESTRUCTA;