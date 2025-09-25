PCLFS_CLIENT_LFF_HANDLER_COMPLETE_CALLBACK PclfsClientLffHandlerCompleteCallback;

VOID PclfsClientLffHandlerCompleteCallback(
  [in] PLOG_FILE_OBJECT LogFile,
  [in] NTSTATUS OperationStatus,
  [in] BOOLEAN LogIsPinned,
  [in] PVOID ClientData
)
{...}