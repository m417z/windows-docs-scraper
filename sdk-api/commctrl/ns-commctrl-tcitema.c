typedef struct tagTCITEMA {
  UINT   mask;
  DWORD  dwState;
  DWORD  dwStateMask;
  LPSTR  pszText;
  int    cchTextMax;
  int    iImage;
  LPARAM lParam;
} TCITEMA, *LPTCITEMA;