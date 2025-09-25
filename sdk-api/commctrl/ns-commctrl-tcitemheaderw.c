typedef struct tagTCITEMHEADERW {
  UINT   mask;
  UINT   lpReserved1;
  UINT   lpReserved2;
  LPWSTR pszText;
  int    cchTextMax;
  int    iImage;
} TCITEMHEADERW, *LPTCITEMHEADERW;