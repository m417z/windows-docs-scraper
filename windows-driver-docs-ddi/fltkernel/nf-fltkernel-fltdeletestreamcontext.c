NTSTATUS FLTAPI FltDeleteStreamContext(
  [in]  PFLT_INSTANCE Instance,
  [in]  PFILE_OBJECT  FileObject,
  [out] PFLT_CONTEXT  *OldContext
);