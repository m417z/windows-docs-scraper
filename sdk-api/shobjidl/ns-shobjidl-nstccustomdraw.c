typedef struct NSTCCUSTOMDRAW {
  IShellItem    *psi;
  UINT          uItemState;
  NSTCITEMSTATE nstcis;
  LPCWSTR       pszText;
  int           iImage;
  HIMAGELIST    himl;
  int           iLevel;
  int           iIndent;
} NSTCCUSTOMDRAW;