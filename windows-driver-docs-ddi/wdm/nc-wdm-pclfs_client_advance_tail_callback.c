PCLFS_CLIENT_ADVANCE_TAIL_CALLBACK PclfsClientAdvanceTailCallback;

NTSTATUS PclfsClientAdvanceTailCallback(
  [in] PLOG_FILE_OBJECT LogFile,
  [in] PCLFS_LSN TargetLsn,
  [in] PVOID ClientData
)
{...}