typedef struct {
  UINT       cbSize;
  POINT      pt;
  UINT       uHit;
  SYSTEMTIME st;
  RECT       rc;
  int        iOffset;
  int        iRow;
  int        iCol;
} MCHITTESTINFO, *PMCHITTESTINFO;