RTL_QUERY_REGISTRY_ROUTINE RtlQueryRegistryRoutine;

NTSTATUS RtlQueryRegistryRoutine(
  [in]           PWSTR ValueName,
  [in]           ULONG ValueType,
  [in]           PVOID ValueData,
  [in]           ULONG ValueLength,
  [in, optional] PVOID Context,
  [in, optional] PVOID EntryContext
)
{...}