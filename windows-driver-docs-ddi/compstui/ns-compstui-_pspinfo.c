typedef struct _PSPINFO {
  WORD            cbSize;
  WORD            wReserved;
  HANDLE          hComPropSheet;
  HANDLE          hCPSUIPage;
  PFNCOMPROPSHEET pfnComPropSheet;
} PSPINFO, *PPSPINFO;