typedef struct tagLVBKIMAGEA {
  ULONG   ulFlags;
  HBITMAP hbm;
  LPSTR   pszImage;
  UINT    cchImageMax;
  int     xOffsetPercent;
  int     yOffsetPercent;
} LVBKIMAGEA, *LPLVBKIMAGEA;