PWINDBG_WRITE_PROCESS_MEMORY_ROUTINE PwindbgWriteProcessMemoryRoutine;

ULONG PwindbgWriteProcessMemoryRoutine(
  ULONG_PTR offset,
  LPCVOID lpBuffer,
  ULONG cb,
  PULONG lpcbBytesWritten
)
{...}