HRESULT MxdcGetPDEVAdjustment(
  [in]           HANDLE                    hPrinter,
  [in]           ULONG                     cbDevMode,
  [in]           const DEVMODE             *pDevMode,
  [in]           ULONG                     cbIn,
  [in, optional] const VOID                *pvIn,
  [in]           ULONG                     cbPrintPropertiesCollection,
                 PrintPropertiesCollection *pPrintPropertiesCollection
);