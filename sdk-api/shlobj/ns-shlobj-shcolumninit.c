typedef struct {
  ULONG dwFlags;
  ULONG dwReserved;
  WCHAR wszFolder[MAX_PATH];
} SHCOLUMNINIT, *LPSHCOLUMNINIT;