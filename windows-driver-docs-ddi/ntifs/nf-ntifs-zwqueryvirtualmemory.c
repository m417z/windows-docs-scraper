NTSYSAPI NTSTATUS ZwQueryVirtualMemory(
  [in]            HANDLE                   ProcessHandle,
  [in, optional]  PVOID                    BaseAddress,
  [in]            MEMORY_INFORMATION_CLASS MemoryInformationClass,
  [out]           PVOID                    MemoryInformation,
  [in]            SIZE_T                   MemoryInformationLength,
  [out, optional] PSIZE_T                  ReturnLength
);