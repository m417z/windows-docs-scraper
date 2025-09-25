typedef struct tagPICTDESC {
  UINT  cbSizeofstruct;
  UINT  picType;
  union {
    struct {
      HBITMAP  hbitmap;
      HPALETTE hpal;
    } bmp;
    struct {
      HMETAFILE hmeta;
      int       xExt;
      int       yExt;
    } wmf;
    struct {
      HICON hicon;
    } icon;
    struct {
      HENHMETAFILE hemf;
    } emf;
  };
} PICTDESC, *LPPICTDESC;