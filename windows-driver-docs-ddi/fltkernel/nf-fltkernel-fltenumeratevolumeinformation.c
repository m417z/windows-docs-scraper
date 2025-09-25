NTSTATUS FLTAPI FltEnumerateVolumeInformation(
  [in]  PFLT_FILTER                     Filter,
  [in]  ULONG                           Index,
  [in]  FILTER_VOLUME_INFORMATION_CLASS InformationClass,
  [out] PVOID                           Buffer,
  [in]  ULONG                           BufferSize,
  [out] PULONG                          BytesReturned
);