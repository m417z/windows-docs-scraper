typedef struct _SHFILEOPSTRUCTW {
  HWND         hwnd;
  UINT         wFunc;
  PCZZWSTR     pFrom;
  PCZZWSTR     pTo;
  FILEOP_FLAGS fFlags;
  BOOL         fAnyOperationsAborted;
  LPVOID       hNameMappings;
  PCWSTR       lpszProgressTitle;
} SHFILEOPSTRUCTW, *LPSHFILEOPSTRUCTW;