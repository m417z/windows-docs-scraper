typedef struct _OPEN_PRINTER_PROPS_INFOW {
  DWORD  dwSize;
  LPWSTR pszSheetName;
  UINT   uSheetIndex;
  DWORD  dwFlags;
  BOOL   bModal;
} OPEN_PRINTER_PROPS_INFOW, *POPEN_PRINTER_PROPS_INFOW;