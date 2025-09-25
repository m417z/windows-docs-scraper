typedef struct tagPOLYTEXTW {
  int     x;
  int     y;
  UINT    n;
  LPCWSTR lpstr;
  UINT    uiFlags;
  RECT    rcl;
  int     *pdx;
} POLYTEXTW, *PPOLYTEXTW, *NPPOLYTEXTW, *LPPOLYTEXTW;