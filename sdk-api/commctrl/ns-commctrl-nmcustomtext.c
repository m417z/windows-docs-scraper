typedef struct tagNMCUSTOMTEXT {
  NMHDR   hdr;
  HDC     hDC;
  LPCWSTR lpString;
  int     nCount;
  LPRECT  lpRect;
  UINT    uFormat;
  BOOL    fLink;
} NMCUSTOMTEXT, *LPNMCUSTOMTEXT;