typedef struct tagNMDATETIMEFORMATA {
  NMHDR      nmhdr;
  LPCSTR     pszFormat;
  SYSTEMTIME st;
  LPCSTR     pszDisplay;
  CHAR       szDisplay[64];
} NMDATETIMEFORMATA, *LPNMDATETIMEFORMATA;