typedef struct _DEVQUERYPRINT_INFO {
  WORD    cbSize;
  WORD    Level;
  HANDLE  hPrinter;
  DEVMODE *pDevMode;
  LPWSTR  pszErrorStr;
  DWORD   cchErrorStr;
  DWORD   cchNeeded;
} DEVQUERYPRINT_INFO, *PDEVQUERYPRINT_INFO;