BOOL QueryVirtualMemoryInformation(
  [in]            HANDLE                         Process,
  [in]            const VOID                     *VirtualAddress,
  [in]            WIN32_MEMORY_INFORMATION_CLASS MemoryInformationClass,
  [out]           PVOID                          MemoryInformation,
  [in]            SIZE_T                         MemoryInformationSize,
  [out, optional] PSIZE_T                        ReturnSize
);