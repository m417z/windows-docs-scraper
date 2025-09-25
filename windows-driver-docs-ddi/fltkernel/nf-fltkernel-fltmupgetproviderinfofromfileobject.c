NTSTATUS FLTAPI FltMupGetProviderInfoFromFileObject(
  PFLT_INSTANCE Instance,
  PFILE_OBJECT  FileObject,
  ULONG         Level,
  PVOID         Buffer,
  PULONG        BufferSize
);