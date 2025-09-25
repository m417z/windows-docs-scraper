typedef struct tagNMDATETIMESTRINGA {
  NMHDR      nmhdr;
  LPCSTR     pszUserString;
  SYSTEMTIME st;
  DWORD      dwFlags;
} NMDATETIMESTRINGA, *LPNMDATETIMESTRINGA;