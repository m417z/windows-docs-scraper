typedef struct tagNMTVGETINFOTIPA {
  NMHDR     hdr;
  LPSTR     pszText;
  int       cchTextMax;
  HTREEITEM hItem;
  LPARAM    lParam;
} NMTVGETINFOTIPA, *LPNMTVGETINFOTIPA;