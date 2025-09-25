typedef struct _OEMFONTINSTPARAM {
  DWORD  cbSize;
  HANDLE hPrinter;
  HANDLE hModule;
  HANDLE hHeap;
  DWORD  dwFlags;
  PWSTR  pFontInstallerName;
} OEMFONTINSTPARAM, *POEMFONTINSTPARAM;