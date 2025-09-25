BCLASS_QUERY_INFORMATION_CALLBACK BclassQueryInformationCallback;

NTSTATUS BclassQueryInformationCallback(
  [in]  PVOID Context,
  [in]  ULONG BatteryTag,
  [in]  BATTERY_QUERY_INFORMATION_LEVEL Level,
  [in]  LONG AtRate,
  [out] PVOID Buffer,
  [in]  ULONG BufferLength,
  [out] PULONG ReturnedLength
)
{...}