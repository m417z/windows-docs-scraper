NTSTATUS FLTAPI FltEnumerateFilterInformation(
  [in]  ULONG                    Index,
  [in]  FILTER_INFORMATION_CLASS InformationClass,
  [out] PVOID                    Buffer,
  [in]  ULONG                    BufferSize,
  [out] PULONG                   BytesReturned
);