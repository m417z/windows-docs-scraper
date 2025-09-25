NTSTATUS FLTAPI FltEnumerateInstanceInformationByVolume(
  [in]  PFLT_VOLUME                Volume,
  [in]  ULONG                      Index,
  [in]  INSTANCE_INFORMATION_CLASS InformationClass,
  [out] PVOID                      Buffer,
  [in]  ULONG                      BufferSize,
  [out] PULONG                     BytesReturned
);