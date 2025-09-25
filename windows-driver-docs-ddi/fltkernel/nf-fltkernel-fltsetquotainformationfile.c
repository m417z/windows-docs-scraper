NTSTATUS FLTAPI FltSetQuotaInformationFile(
  [in] PFLT_INSTANCE Instance,
  [in] PFILE_OBJECT  FileObject,
  [in] PVOID         Buffer,
  [in] ULONG         Length
);