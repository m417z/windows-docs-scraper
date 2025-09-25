typedef struct _SHFILEOPSTRUCTA {
  HWND         hwnd;
  UINT         wFunc;
  PCZZSTR      pFrom;
  PCZZSTR      pTo;
  FILEOP_FLAGS fFlags;
  BOOL         fAnyOperationsAborted;
  LPVOID       hNameMappings;
  PCSTR        lpszProgressTitle;
} SHFILEOPSTRUCTA, *LPSHFILEOPSTRUCTA;