BCLASS_SET_STATUS_NOTIFY_CALLBACK BclassSetStatusNotifyCallback;

NTSTATUS BclassSetStatusNotifyCallback(
  [in] PVOID Context,
  [in] ULONG BatteryTag,
  [in] PBATTERY_NOTIFY BatteryNotify
)
{...}