typedef struct _TTGETTITLE {
  DWORD dwSize;
  UINT  uTitleBitmap;
  UINT  cch;
  WCHAR *pszTitle;
} TTGETTITLE, *PTTGETTITLE;