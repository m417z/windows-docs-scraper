typedef struct _OEMCUIPPARAM {
  DWORD           cbSize;
  POEMUIOBJ       poemuiobj;
  HANDLE          hPrinter;
  PWSTR           pPrinterName;
  HANDLE          hModule;
  HANDLE          hOEMHeap;
  PDEVMODE        pPublicDM;
  PVOID           pOEMDM;
  DWORD           dwFlags;
  POPTITEM        pDrvOptItems;
  DWORD           cDrvOptItems;
  POPTITEM        pOEMOptItems;
  DWORD           cOEMOptItems;
  PVOID           pOEMUserData;
  OEMCUIPCALLBACK OEMCUIPCallback;
} *POEMCUIPPARAM, OEMCUIPPARAM;