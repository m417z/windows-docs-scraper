typedef struct _DOCUMENTPROPERTYHEADER {
  WORD     cbSize;
  WORD     Reserved;
  HANDLE   hPrinter;
  LPTSTR   pszPrinterName;
  PDEVMODE pdmIn;
  PDEVMODE pdmOut;
  DWORD    cbOut;
  DWORD    fMode;
} DOCUMENTPROPERTYHEADER, *PDOCUMENTPROPERTYHEADER;