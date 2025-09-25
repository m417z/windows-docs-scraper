typedef struct tagNMLVGETINFOTIPA {
  NMHDR  hdr;
  DWORD  dwFlags;
  LPSTR  pszText;
  int    cchTextMax;
  int    iItem;
  int    iSubItem;
  LPARAM lParam;
} NMLVGETINFOTIPA, *LPNMLVGETINFOTIPA;