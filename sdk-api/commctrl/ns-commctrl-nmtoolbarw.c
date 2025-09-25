typedef struct tagNMTOOLBARW {
  NMHDR    hdr;
  int      iItem;
  TBBUTTON tbButton;
  int      cchText;
  LPWSTR   pszText;
  RECT     rcButton;
} NMTOOLBARW, *LPNMTOOLBARW;