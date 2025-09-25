HRESULT AdjustImageCompression(
  HANDLE         hPrinter,
  DWORD          cbDevMode,
  const PDEVMODE pDevMode,
  DWORD          cbOEMDM,
  const PVOID    pOEMDM,
  PLONG          pCompressionMode
);