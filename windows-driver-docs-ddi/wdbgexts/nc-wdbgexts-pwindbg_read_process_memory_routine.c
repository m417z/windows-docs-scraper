PWINDBG_READ_PROCESS_MEMORY_ROUTINE PwindbgReadProcessMemoryRoutine;

ULONG PwindbgReadProcessMemoryRoutine(
  ULONG_PTR offset,
  PVOID lpBuffer,
  ULONG cb,
  PULONG lpcbBytesRead
)
{...}