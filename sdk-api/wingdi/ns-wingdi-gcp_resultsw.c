typedef struct tagGCP_RESULTSW {
  DWORD  lStructSize;
  LPWSTR lpOutString;
  UINT   *lpOrder;
  int    *lpDx;
  int    *lpCaretPos;
  LPSTR  lpClass;
  LPWSTR lpGlyphs;
  UINT   nGlyphs;
  int    nMaxFit;
} GCP_RESULTSW, *LPGCP_RESULTSW;