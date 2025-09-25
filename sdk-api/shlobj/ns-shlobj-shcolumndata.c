typedef struct {
  ULONG dwFlags;
  DWORD dwFileAttributes;
  ULONG dwReserved;
  WCHAR *pwszExt;
  WCHAR wszFile[MAX_PATH];
} SHCOLUMNDATA, *LPSHCOLUMNDATA;