NTSTATUS FLTAPI FltEnumerateInstanceInformationByFilter(
  [in]  PFLT_FILTER                Filter,
  [in]  ULONG                      Index,
  [in]  INSTANCE_INFORMATION_CLASS InformationClass,
  [out] PVOID                      Buffer,
  [in]  ULONG                      BufferSize,
  [out] PULONG                     BytesReturned
);