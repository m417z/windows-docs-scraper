typedef struct tagNMTBGETINFOTIPW {
  NMHDR  hdr;
  LPWSTR pszText;
  int    cchTextMax;
  int    iItem;
  LPARAM lParam;
} NMTBGETINFOTIPW, *LPNMTBGETINFOTIPW;