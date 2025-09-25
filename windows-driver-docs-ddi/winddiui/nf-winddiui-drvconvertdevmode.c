BOOL DrvConvertDevMode(
  [in]      LPTSTR   pPrinterName,
  [in]      PDEVMODE pdmIn,
  [out]     PDEVMODE pdmOut,
  [in, out] PLONG    pcbNeeded,
  [in]      DWORD    fMode
);