NTSTATUS FLTAPI FltFsControlFile(
  [in]            PFLT_INSTANCE Instance,
  [in]            PFILE_OBJECT  FileObject,
  [in]            ULONG         FsControlCode,
  [in, optional]  PVOID         InputBuffer,
  [in]            ULONG         InputBufferLength,
  [out, optional] PVOID         OutputBuffer,
  [in]            ULONG         OutputBufferLength,
  [out, optional] PULONG        LengthReturned
);