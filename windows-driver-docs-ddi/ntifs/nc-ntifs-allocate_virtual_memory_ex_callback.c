ALLOCATE_VIRTUAL_MEMORY_EX_CALLBACK AllocateVirtualMemoryExCallback;

NTSTATUS AllocateVirtualMemoryExCallback(
  HANDLE CallbackContext,
  HANDLE ProcessHandle,
  PVOID *BaseAddress,
  PSIZE_T RegionSize,
  ULONG AllocationType,
  ULONG PageProtection,
  PMEM_EXTENDED_PARAMETER ExtendedParameters,
  ULONG ExtendedParameterCount
)
{...}