PLOG_FULL_HANDLER_CALLBACK PlogFullHandlerCallback;

VOID PlogFullHandlerCallback(
  [in] HANDLE hLogFile,
  [in] DWORD dwError,
  [in] BOOL fLogIsPinned,
  [in] PVOID pvClientContext
)
{...}