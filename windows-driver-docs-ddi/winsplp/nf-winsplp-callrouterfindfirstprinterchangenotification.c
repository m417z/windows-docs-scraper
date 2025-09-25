DWORD CallRouterFindFirstPrinterChangeNotification(
  [in] HANDLE                  hPrinterRPC,
       DWORD                   fdwFilterFlags,
       DWORD                   fdwOptions,
  [in] HANDLE                  hNotify,
  [in] PPRINTER_NOTIFY_OPTIONS pPrinterNotifyOptions
);