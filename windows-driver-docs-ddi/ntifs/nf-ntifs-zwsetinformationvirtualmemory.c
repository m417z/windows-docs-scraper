NTSYSAPI NTSTATUS ZwSetInformationVirtualMemory(
  [in] HANDLE                           ProcessHandle,
  [in] VIRTUAL_MEMORY_INFORMATION_CLASS VmInformationClass,
  [in] ULONG_PTR                        NumberOfEntries,
  [in] PMEMORY_RANGE_ENTRY              VirtualAddresses,
  [in] PVOID                            VmInformation,
  [in] ULONG                            VmInformationLength
);