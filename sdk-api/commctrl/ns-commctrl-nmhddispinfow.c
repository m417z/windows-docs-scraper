typedef struct tagNMHDDISPINFOW {
  NMHDR  hdr;
  int    iItem;
  UINT   mask;
  LPWSTR pszText;
  int    cchTextMax;
  int    iImage;
  LPARAM lParam;
} NMHDDISPINFOW, *LPNMHDDISPINFOW;