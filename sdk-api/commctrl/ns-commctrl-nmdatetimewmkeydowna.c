typedef struct tagNMDATETIMEWMKEYDOWNA {
  NMHDR      nmhdr;
  int        nVirtKey;
  LPCSTR     pszFormat;
  SYSTEMTIME st;
} NMDATETIMEWMKEYDOWNA, *LPNMDATETIMEWMKEYDOWNA;