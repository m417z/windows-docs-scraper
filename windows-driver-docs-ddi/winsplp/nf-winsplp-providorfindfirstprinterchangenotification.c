BOOL ProvidorFindFirstPrinterChangeNotification(
  [in]            HANDLE hPrinter,
                  DWORD  fdwFlags,
                  DWORD  fdwOptions,
  [in]            HANDLE hNotify,
  [in, optional]  PVOID  pPrinterNotifyOptions,
  [out, optional] PVOID  pvReserved1
);