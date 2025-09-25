BOOL SpoolerRefreshPrinterChangeNotification(
  [in]                HANDLE                  hPrinter,
  [in]                DWORD                   dwColor,
  [in]                PPRINTER_NOTIFY_OPTIONS pOptions,
  [in, out, optional] PPRINTER_NOTIFY_INFO    *ppInfo
);