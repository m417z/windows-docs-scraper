PREAD_PROCESS_MEMORY_ROUTINE PreadProcessMemoryRoutine;

BOOL PreadProcessMemoryRoutine(
  [in]  HANDLE hProcess,
  [in]  DWORD lpBaseAddress,
  [out] PVOID lpBuffer,
  [in]  DWORD nSize,
  [out] PDWORD lpNumberOfBytesRead
)
{...}