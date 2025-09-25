typedef struct tagALTTABINFO {
  DWORD cbSize;
  int   cItems;
  int   cColumns;
  int   cRows;
  int   iColFocus;
  int   iRowFocus;
  int   cxItem;
  int   cyItem;
  POINT ptStart;
} ALTTABINFO, *PALTTABINFO, *LPALTTABINFO;