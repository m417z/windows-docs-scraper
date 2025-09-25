typedef struct _DEVOBJ {
  DWORD     dwSize;
  PDEVOEM   pdevOEM;
  HANDLE    hEngine;
  HANDLE    hPrinter;
  HANDLE    hOEM;
  PDEVMODE  pPublicDM;
  PVOID     pOEMDM;
  PDRVPROCS pDrvProcs;
} *PDEVOBJ, DEVOBJ;