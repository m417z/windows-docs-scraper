FREE_VIRTUAL_MEMORY_EX_CALLBACK FreeVirtualMemoryExCallback;

NTSTATUS FreeVirtualMemoryExCallback(
  HANDLE CallbackContext,
  HANDLE ProcessHandle,
  PVOID *BaseAddress,
  PSIZE_T RegionSize,
  ULONG FreeType
)
{...}