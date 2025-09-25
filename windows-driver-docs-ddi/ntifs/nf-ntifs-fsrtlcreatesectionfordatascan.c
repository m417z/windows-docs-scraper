NTSTATUS FsRtlCreateSectionForDataScan(
  [out]           PHANDLE            SectionHandle,
  [out]           PVOID              *SectionObject,
  [out, optional] PLARGE_INTEGER     SectionFileSize,
  [in]            PFILE_OBJECT       FileObject,
  [in]            ACCESS_MASK        DesiredAccess,
  [in, optional]  POBJECT_ATTRIBUTES ObjectAttributes,
  [in, optional]  PLARGE_INTEGER     MaximumSize,
  [in]            ULONG              SectionPageProtection,
  [in]            ULONG              AllocationAttributes,
  [in]            ULONG              Flags
);