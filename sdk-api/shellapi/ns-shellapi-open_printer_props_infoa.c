typedef struct _OPEN_PRINTER_PROPS_INFOA {
  DWORD dwSize;
  LPSTR pszSheetName;
  UINT  uSheetIndex;
  DWORD dwFlags;
  BOOL  bModal;
} OPEN_PRINTER_PROPS_INFOA, *POPEN_PRINTER_PROPS_INFOA;