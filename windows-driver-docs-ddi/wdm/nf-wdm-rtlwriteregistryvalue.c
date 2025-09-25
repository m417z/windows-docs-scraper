NTSYSAPI NTSTATUS RtlWriteRegistryValue(
  [in]           ULONG  RelativeTo,
  [in]           PCWSTR Path,
  [in]           PCWSTR ValueName,
  [in]           ULONG  ValueType,
  [in, optional] PVOID  ValueData,
  [in]           ULONG  ValueLength
);