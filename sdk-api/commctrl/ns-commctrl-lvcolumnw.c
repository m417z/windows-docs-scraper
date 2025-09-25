typedef struct tagLVCOLUMNW {
  UINT   mask;
  int    fmt;
  int    cx;
  LPWSTR pszText;
  int    cchTextMax;
  int    iSubItem;
  int    iImage;
  int    iOrder;
  int    cxMin;
  int    cxDefault;
  int    cxIdeal;
} LVCOLUMNW, *LPLVCOLUMNW;