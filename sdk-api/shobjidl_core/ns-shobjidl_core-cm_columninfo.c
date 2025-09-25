typedef struct CM_COLUMNINFO {
  DWORD cbSize;
  DWORD dwMask;
  DWORD dwState;
  UINT  uWidth;
  UINT  uDefaultWidth;
  UINT  uIdealWidth;
  WCHAR wszName[80];
} CM_COLUMNINFO;