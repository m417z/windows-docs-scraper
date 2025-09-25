typedef struct _OEMDMPARAM {
  DWORD    cbSize;
  PVOID    pdriverobj;
  HANDLE   hPrinter;
  HANDLE   hModule;
  PDEVMODE pPublicDMIn;
  PDEVMODE pPublicDMOut;
  PVOID    pOEMDMIn;
  PVOID    pOEMDMOut;
  DWORD    cbBufSize;
} OEMDMPARAM, *POEMDMPARAM;