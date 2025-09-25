NTSTATUS FLTAPI FltGetFilterInformation(
  [in]  PFLT_FILTER              Filter,
  [in]  FILTER_INFORMATION_CLASS InformationClass,
  [out] PVOID                    Buffer,
  [in]  ULONG                    BufferSize,
  [out] PULONG                   BytesReturned
);