typedef struct tagNMTOOLBARA {
  NMHDR    hdr;
  int      iItem;
  TBBUTTON tbButton;
  int      cchText;
  LPSTR    pszText;
  RECT     rcButton;
} NMTOOLBARA, *LPNMTOOLBARA;