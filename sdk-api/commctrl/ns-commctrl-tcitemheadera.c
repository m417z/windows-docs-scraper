typedef struct tagTCITEMHEADERA {
  UINT  mask;
  UINT  lpReserved1;
  UINT  lpReserved2;
  LPSTR pszText;
  int   cchTextMax;
  int   iImage;
} TCITEMHEADERA, *LPTCITEMHEADERA;