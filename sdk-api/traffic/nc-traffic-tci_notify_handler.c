TCI_NOTIFY_HANDLER TciNotifyHandler;

VOID TciNotifyHandler(
  [in] HANDLE ClRegCtx,
  [in] HANDLE ClIfcCtx,
  [in] ULONG Event,
  [in] HANDLE SubCode,
  [in] ULONG BufSize,
  [in] PVOID Buffer
)
{...}