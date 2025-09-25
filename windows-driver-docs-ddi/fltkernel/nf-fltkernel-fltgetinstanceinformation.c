NTSTATUS FLTAPI FltGetInstanceInformation(
  [in]  PFLT_INSTANCE              Instance,
  [in]  INSTANCE_INFORMATION_CLASS InformationClass,
  [out] PVOID                      Buffer,
  [in]  ULONG                      BufferSize,
  [out] PULONG                     BytesReturned
);