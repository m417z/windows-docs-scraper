BOOL PrefetchVirtualMemory(
  [in] HANDLE                    hProcess,
  [in] ULONG_PTR                 NumberOfEntries,
  [in] PWIN32_MEMORY_RANGE_ENTRY VirtualAddresses,
  [in] ULONG                     Flags
);