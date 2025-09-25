BOOL SpoolerFindNextPrinterChangeNotification(
  [in]                HANDLE  hPrinter,
  [out]               LPDWORD pfdwChange,
  [in, optional]      LPVOID  pPrinterNotifyOptions,
  [in, out, optional] LPVOID  *ppPrinterNotifyInfo
);