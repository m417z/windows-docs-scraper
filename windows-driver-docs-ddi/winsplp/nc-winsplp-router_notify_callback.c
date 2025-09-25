ROUTER_NOTIFY_CALLBACK RouterNotifyCallback;

BOOL RouterNotifyCallback(
  [in]  DWORD dwCommand,
  [in]  PVOID pContext,
  [in]  DWORD dwColor,
  [in]  PPRINTER_NOTIFY_INFO pNofityInfo,
  [in]  DWORD fdwFlags,
  [out] PDWORD pdwResult
)
{...}