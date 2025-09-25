BCLASS_QUERY_STATUS_CALLBACK BclassQueryStatusCallback;

NTSTATUS BclassQueryStatusCallback(
  [in]  PVOID Context,
  [in]  ULONG BatteryTag,
  [out] PBATTERY_STATUS BatteryStatus
)
{...}