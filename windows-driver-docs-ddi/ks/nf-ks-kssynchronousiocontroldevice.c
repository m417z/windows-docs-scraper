KSDDKAPI NTSTATUS KsSynchronousIoControlDevice(
  [in]  PFILE_OBJECT    FileObject,
        KPROCESSOR_MODE RequestorMode,
  [in]  ULONG           IoControl,
  [in]  PVOID           InBuffer,
  [in]  ULONG           InSize,
  [out] PVOID           OutBuffer,
  [in]  ULONG           OutSize,
  [out] PULONG          BytesReturned
);