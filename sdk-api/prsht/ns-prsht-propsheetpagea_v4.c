typedef struct _PROPSHEETPAGEA_V4 {
  LPCSTR pszHeaderTitle;
  LPCSTR pszHeaderSubTitle;
  HANDLE hActCtx;
  union {
    HBITMAP hbmHeader;
    LPCSTR  pszbmHeader;
  } DUMMYUNIONNAME3;
} PROPSHEETPAGEA_V4, *LPPROPSHEETPAGEA_V4;