typedef struct tagPOLYTEXTA {
  int    x;
  int    y;
  UINT   n;
  LPCSTR lpstr;
  UINT   uiFlags;
  RECT   rcl;
  int    *pdx;
} POLYTEXTA, *PPOLYTEXTA, *NPPOLYTEXTA, *LPPOLYTEXTA;