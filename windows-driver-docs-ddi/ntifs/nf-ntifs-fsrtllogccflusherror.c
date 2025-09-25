NTSTATUS FsRtlLogCcFlushError(
  [in] PUNICODE_STRING          FileName,
  [in] PDEVICE_OBJECT           DeviceObject,
  [in] PSECTION_OBJECT_POINTERS SectionObjectPointer,
  [in] NTSTATUS                 FlushError,
  [in] ULONG                    Flags
);