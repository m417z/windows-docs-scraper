PREAD_PROCESS_MEMORY_ROUTINE64 PreadProcessMemoryRoutine64;

BOOL PreadProcessMemoryRoutine64(
  [in]  HANDLE hProcess,
  [in]  DWORD64 qwBaseAddress,
  [out] PVOID lpBuffer,
  [in]  DWORD nSize,
  [out] LPDWORD lpNumberOfBytesRead
)
{...}