typedef struct _HD_ITEMA {
  UINT    mask;
  int     cxy;
  LPSTR   pszText;
  HBITMAP hbm;
  int     cchTextMax;
  int     fmt;
  LPARAM  lParam;
  int     iImage;
  int     iOrder;
  UINT    type;
  void    *pvFilter;
  UINT    state;
} HDITEMA, *LPHDITEMA;