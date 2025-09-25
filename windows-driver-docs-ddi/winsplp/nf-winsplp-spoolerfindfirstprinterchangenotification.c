BOOL SpoolerFindFirstPrinterChangeNotification(
  [in]            HANDLE  hPrinter,
                  DWORD   fdwFilterFlags,
                  DWORD   fdwOptions,
  [in]            PVOID   pPrinterNotifyOptions,
  [in, optional]  PVOID   pvReserved,
  [in]            PVOID   pNotificationConfig,
  [out, optional] PHANDLE phNotify,
  [out, optional] PHANDLE phEvent
);