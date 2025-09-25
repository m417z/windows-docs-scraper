typedef struct {
  UINT  cbSize;
  DWORD dwMask;
  int   cxPad;
  int   cyPad;
  int   cxBarPad;
  int   cyBarPad;
  int   cxButtonSpacing;
  int   cyButtonSpacing;
} TBMETRICS, *LPTBMETRICS;