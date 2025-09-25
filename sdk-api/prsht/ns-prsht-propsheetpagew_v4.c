typedef struct _PROPSHEETPAGEW_V4 {
  LPCWSTR pszHeaderTitle;
  LPCWSTR pszHeaderSubTitle;
  HANDLE  hActCtx;
  union {
    HBITMAP hbmHeader;
    LPCWSTR pszbmHeader;
  } DUMMYUNIONNAME3;
} PROPSHEETPAGEW_V4, *LPPROPSHEETPAGEW_V4;