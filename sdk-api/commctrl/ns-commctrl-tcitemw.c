typedef struct tagTCITEMW {
  UINT   mask;
  DWORD  dwState;
  DWORD  dwStateMask;
  LPWSTR pszText;
  int    cchTextMax;
  int    iImage;
  LPARAM lParam;
} TCITEMW, *LPTCITEMW;