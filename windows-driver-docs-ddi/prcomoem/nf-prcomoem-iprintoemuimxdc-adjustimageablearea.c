HRESULT AdjustImageableArea(
  HANDLE         hPrinter,
  DWORD          cbDevMode,
  const PDEVMODE pDevMode,
  DWORD          cbOEMDM,
  const PVOID    pOEMDM,
  PRECTL         prclImageableArea
);