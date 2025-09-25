typedef struct tagNMLVGETINFOTIPW {
  NMHDR  hdr;
  DWORD  dwFlags;
  LPWSTR pszText;
  int    cchTextMax;
  int    iItem;
  int    iSubItem;
  LPARAM lParam;
} NMLVGETINFOTIPW, *LPNMLVGETINFOTIPW;