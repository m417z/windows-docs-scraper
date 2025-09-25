NTSTATUS FLTAPI FltGetVolumeInformation(
  [in]  PFLT_VOLUME                     Volume,
  [in]  FILTER_VOLUME_INFORMATION_CLASS InformationClass,
  [out] PVOID                           Buffer,
  [in]  ULONG                           BufferSize,
  [out] PULONG                          BytesReturned
);