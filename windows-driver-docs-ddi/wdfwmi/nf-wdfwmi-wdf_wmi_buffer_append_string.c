NTSTATUS WDF_WMI_BUFFER_APPEND_STRING(
  [out] PVOID            Buffer,
  [in]  ULONG            BufferLength,
  [in]  PCUNICODE_STRING String,
  [out] PULONG           RequiredSize
);