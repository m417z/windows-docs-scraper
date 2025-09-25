PCREATE_THREAD_NOTIFY_ROUTINE PcreateThreadNotifyRoutine;

VOID PcreateThreadNotifyRoutine(
  [in] HANDLE ProcessId,
  [in] HANDLE ThreadId,
  [in] BOOLEAN Create
)
{...}