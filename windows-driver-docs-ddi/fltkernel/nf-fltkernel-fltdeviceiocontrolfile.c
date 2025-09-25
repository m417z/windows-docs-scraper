NTSTATUS FLTAPI FltDeviceIoControlFile(
  [in]            PFLT_INSTANCE Instance,
  [in]            PFILE_OBJECT  FileObject,
  [in]            ULONG         IoControlCode,
  [in, optional]  PVOID         InputBuffer,
  [in]            ULONG         InputBufferLength,
  [out]           PVOID         OutputBuffer,
  [in]            ULONG         OutputBufferLength,
  [out, optional] PULONG        LengthReturned
);