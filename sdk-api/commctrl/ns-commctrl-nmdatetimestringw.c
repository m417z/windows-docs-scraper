typedef struct tagNMDATETIMESTRINGW {
  NMHDR      nmhdr;
  LPCWSTR    pszUserString;
  SYSTEMTIME st;
  DWORD      dwFlags;
} NMDATETIMESTRINGW, *LPNMDATETIMESTRINGW;