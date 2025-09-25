HRESULT AdjustDPI(
  HANDLE         hPrinter,
  DWORD          cbDevMode,
  const PDEVMODE pDevMode,
  DWORD          cbOEMDM,
  const PVOID    pOEMDM,
  PLONG          pDPI
);