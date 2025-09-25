NTSYSAPI NTSTATUS RtlQueryRegistryValueWithFallback(
  [in]  HANDLE          PrimaryHandle,
  [in]  HANDLE          FallbackHandle,
  [in]  PUNICODE_STRING ValueName,
  [in]  ULONG           ValueLength,
  [Out] PULONG          ValueType,
  [out] PVOID           ValueData,
  [out] PULONG          ResultLength
);