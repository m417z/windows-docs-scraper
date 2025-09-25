BCLASS_SET_INFORMATION_CALLBACK BclassSetInformationCallback;

NTSTATUS BclassSetInformationCallback(
  [in] PVOID Context,
  [in] ULONG BatteryTag,
  [in] BATTERY_SET_INFORMATION_LEVEL Level,
  [in] PVOID Buffer
)
{...}