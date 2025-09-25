typedef struct tagNMTVGETINFOTIPW {
  NMHDR     hdr;
  LPWSTR    pszText;
  int       cchTextMax;
  HTREEITEM hItem;
  LPARAM    lParam;
} NMTVGETINFOTIPW, *LPNMTVGETINFOTIPW;