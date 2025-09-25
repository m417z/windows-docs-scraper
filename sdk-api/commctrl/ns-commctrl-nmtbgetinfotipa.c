typedef struct tagNMTBGETINFOTIPA {
  NMHDR  hdr;
  LPSTR  pszText;
  int    cchTextMax;
  int    iItem;
  LPARAM lParam;
} NMTBGETINFOTIPA, *LPNMTBGETINFOTIPA;