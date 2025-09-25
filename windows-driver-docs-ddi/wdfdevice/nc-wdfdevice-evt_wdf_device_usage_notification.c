EVT_WDF_DEVICE_USAGE_NOTIFICATION EvtWdfDeviceUsageNotification;

VOID EvtWdfDeviceUsageNotification(
  [in] WDFDEVICE Device,
  [in] WDF_SPECIAL_FILE_TYPE NotificationType,
  [in] BOOLEAN IsInNotificationPath
)
{...}