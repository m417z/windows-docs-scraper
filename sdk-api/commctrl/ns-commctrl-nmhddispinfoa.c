typedef struct tagNMHDDISPINFOA {
  NMHDR  hdr;
  int    iItem;
  UINT   mask;
  LPSTR  pszText;
  int    cchTextMax;
  int    iImage;
  LPARAM lParam;
} NMHDDISPINFOA, *LPNMHDDISPINFOA;