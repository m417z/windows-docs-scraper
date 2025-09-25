typedef struct tagLVBKIMAGEW {
  ULONG   ulFlags;
  HBITMAP hbm;
  LPWSTR  pszImage;
  UINT    cchImageMax;
  int     xOffsetPercent;
  int     yOffsetPercent;
} LVBKIMAGEW, *LPLVBKIMAGEW;