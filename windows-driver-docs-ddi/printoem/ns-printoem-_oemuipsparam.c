typedef struct _OEMUIPSPARAM {
  DWORD     cbSize;
  POEMUIOBJ poemuiobj;
  HANDLE    hPrinter;
  PWSTR     pPrinterName;
  HANDLE    hModule;
  HANDLE    hOEMHeap;
  PDEVMODE  pPublicDM;
  PVOID     pOEMDM;
  PVOID     pOEMUserData;
  DWORD     dwFlags;
  PVOID     pOemEntry;
} OEMUIPSPARAM, *POEMUIPSPARAM;