PCREATE_PROCESS_NOTIFY_ROUTINE PcreateProcessNotifyRoutine;

VOID PcreateProcessNotifyRoutine(
  [in] HANDLE ParentId,
  [in] HANDLE ProcessId,
  [in] BOOLEAN Create
)
{...}