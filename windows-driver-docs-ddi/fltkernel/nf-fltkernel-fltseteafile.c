NTSTATUS FLTAPI FltSetEaFile(
  [in] PFLT_INSTANCE Instance,
  [in] PFILE_OBJECT  FileObject,
  [in] PVOID         EaBuffer,
  [in] ULONG         Length
);