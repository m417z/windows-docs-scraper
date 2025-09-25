EVT_WDF_DEVICE_USAGE_NOTIFICATION_EX EvtWdfDeviceUsageNotificationEx;

NTSTATUS EvtWdfDeviceUsageNotificationEx(
  [in] WDFDEVICE Device,
  [in] WDF_SPECIAL_FILE_TYPE NotificationType,
  [in] BOOLEAN IsInNotificationPath
)
{...}