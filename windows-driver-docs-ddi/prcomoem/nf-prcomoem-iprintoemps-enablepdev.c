HRESULT EnablePDEV(
        PDEVOBJ       pdevobj,
        PWSTR         pPrinterName,
        ULONG         cPatterns,
        HSURF         *phsurfPatterns,
        ULONG         cjGdiInfo,
        GDIINFO       *pGdiInfo,
        ULONG         cjDevInfo,
        DEVINFO       *pDevInfo,
        DRVENABLEDATA *pded,
  [out] OUT PDEVOEM   *pDevOem
);