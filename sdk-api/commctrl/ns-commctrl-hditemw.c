typedef struct _HD_ITEMW {
  UINT    mask;
  int     cxy;
  LPWSTR  pszText;
  HBITMAP hbm;
  int     cchTextMax;
  int     fmt;
  LPARAM  lParam;
  int     iImage;
  int     iOrder;
  UINT    type;
  void    *pvFilter;
  UINT    state;
} HDITEMW, *LPHDITEMW;