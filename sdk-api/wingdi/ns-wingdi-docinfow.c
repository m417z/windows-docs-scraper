typedef struct _DOCINFOW {
  int     cbSize;
  LPCWSTR lpszDocName;
  LPCWSTR lpszOutput;
  LPCWSTR lpszDatatype;
  DWORD   fwType;
} DOCINFOW, *LPDOCINFOW;