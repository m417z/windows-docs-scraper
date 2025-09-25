PLOG_TAIL_ADVANCE_CALLBACK PlogTailAdvanceCallback;

VOID PlogTailAdvanceCallback(
  [in] HANDLE hLogFile,
  [in] CLFS_LSN lsnTarget,
  [in] PVOID pvClientContext
)
{...}