NTSYSAPI NTSTATUS ZwMapViewOfSectionEx(
  [in]                HANDLE                  SectionHandle,
  [in]                HANDLE                  ProcessHandle,
  [in, out]           PVOID                   *BaseAddress,
  [in, out, optional] PLARGE_INTEGER          SectionOffset,
  [in, out]           PSIZE_T                 ViewSize,
  [in]                ULONG                   AllocationType,
  [in]                ULONG                   PageProtection,
  [in, out, optional] PMEM_EXTENDED_PARAMETER ExtendedParameters,
  [in]                ULONG                   ExtendedParameterCount
);