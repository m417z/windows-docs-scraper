typedef struct tagLVCOLUMNA {
  UINT  mask;
  int   fmt;
  int   cx;
  LPSTR pszText;
  int   cchTextMax;
  int   iSubItem;
  int   iImage;
  int   iOrder;
  int   cxMin;
  int   cxDefault;
  int   cxIdeal;
} LVCOLUMNA, *LPLVCOLUMNA;