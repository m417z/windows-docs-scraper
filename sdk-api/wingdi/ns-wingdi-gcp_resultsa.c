typedef struct tagGCP_RESULTSA {
  DWORD  lStructSize;
  LPSTR  lpOutString;
  UINT   *lpOrder;
  int    *lpDx;
  int    *lpCaretPos;
  LPSTR  lpClass;
  LPWSTR lpGlyphs;
  UINT   nGlyphs;
  int    nMaxFit;
} GCP_RESULTSA, *LPGCP_RESULTSA;