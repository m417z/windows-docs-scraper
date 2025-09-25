NTSYSAPI NTSTATUS ZwCreateSection(
  [out]          PHANDLE            SectionHandle,
  [in]           ACCESS_MASK        DesiredAccess,
  [in, optional] POBJECT_ATTRIBUTES ObjectAttributes,
  [in, optional] PLARGE_INTEGER     MaximumSize,
  [in]           ULONG              SectionPageProtection,
  [in]           ULONG              AllocationAttributes,
  [in, optional] HANDLE             FileHandle
);