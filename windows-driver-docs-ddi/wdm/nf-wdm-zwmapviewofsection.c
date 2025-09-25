NTSYSAPI NTSTATUS ZwMapViewOfSection(
  [in]                HANDLE          SectionHandle,
  [in]                HANDLE          ProcessHandle,
  [in, out]           PVOID           *BaseAddress,
  [in]                ULONG_PTR       ZeroBits,
  [in]                SIZE_T          CommitSize,
  [in, out, optional] PLARGE_INTEGER  SectionOffset,
  [in, out]           PSIZE_T         ViewSize,
  [in]                SECTION_INHERIT InheritDisposition,
  [in]                ULONG           AllocationType,
  [in]                ULONG           Win32Protect
);