NTSTATUS FLTAPI FltCreateSectionForDataScan(
  [in]            PFLT_INSTANCE      Instance,
  [in]            PFILE_OBJECT       FileObject,
  [in]            PFLT_CONTEXT       SectionContext,
  [in]            ACCESS_MASK        DesiredAccess,
  [in, optional]  POBJECT_ATTRIBUTES ObjectAttributes,
  [in, optional]  PLARGE_INTEGER     MaximumSize,
  [in]            ULONG              SectionPageProtection,
  [in]            ULONG              AllocationAttributes,
  [in]            ULONG              Flags,
  [out]           PHANDLE            SectionHandle,
  [out]           PVOID              *SectionObject,
  [out, optional] PLARGE_INTEGER     SectionFileSize
);