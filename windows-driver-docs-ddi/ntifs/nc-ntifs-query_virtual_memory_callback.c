QUERY_VIRTUAL_MEMORY_CALLBACK QueryVirtualMemoryCallback;

NTSTATUS QueryVirtualMemoryCallback(
  HANDLE CallbackContext,
  HANDLE ProcessHandle,
  PVOID BaseAddress,
  HEAP_MEMORY_INFO_CLASS MemoryInformationClass,
  PVOID MemoryInformation,
  SIZE_T MemoryInformationLength,
  PSIZE_T ReturnLength
)
{...}