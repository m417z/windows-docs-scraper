typedef struct tagNMDATETIMEFORMATW {
  NMHDR      nmhdr;
  LPCWSTR    pszFormat;
  SYSTEMTIME st;
  LPCWSTR    pszDisplay;
  WCHAR      szDisplay[64];
} NMDATETIMEFORMATW, *LPNMDATETIMEFORMATW;