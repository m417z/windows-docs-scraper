__kernel_entry NTSYSCALLAPI NTSTATUS NtCreateSectionEx(
  [out]          PHANDLE                 SectionHandle,
  [in]           ACCESS_MASK             DesiredAccess,
  [in, optional] POBJECT_ATTRIBUTES      ObjectAttributes,
  [in, optional] PLARGE_INTEGER          MaximumSize,
  [in]           ULONG                   SectionPageProtection,
  [in]           ULONG                   AllocationAttributes,
  [in, optional] HANDLE                  FileHandle,
  [in/out]       PMEM_EXTENDED_PARAMETER ExtendedParameters,
                 ULONG                   ExtendedParameterCount
);