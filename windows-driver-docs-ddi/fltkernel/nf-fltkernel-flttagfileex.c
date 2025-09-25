NTSTATUS FLTAPI FltTagFileEx(
  PFLT_INSTANCE InitiatingInstance,
  PFILE_OBJECT  FileObject,
  ULONG         FileTag,
  GUID          *Guid,
  PVOID         DataBuffer,
  USHORT        DataBufferLength,
  ULONG         ExistingFileTag,
  GUID          *ExistingGuid,
  ULONG         Flags
);