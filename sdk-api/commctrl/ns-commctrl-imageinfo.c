typedef struct _IMAGEINFO {
  HBITMAP hbmImage;
  HBITMAP hbmMask;
  int     Unused1;
  int     Unused2;
  RECT    rcImage;
} IMAGEINFO, *LPIMAGEINFO;