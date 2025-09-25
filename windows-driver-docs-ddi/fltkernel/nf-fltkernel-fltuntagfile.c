NTSTATUS FLTAPI FltUntagFile(
  [in]           PFLT_INSTANCE InitiatingInstance,
  [in]           PFILE_OBJECT  FileObject,
  [in]           ULONG         FileTag,
  [in, optional] GUID          *Guid
);