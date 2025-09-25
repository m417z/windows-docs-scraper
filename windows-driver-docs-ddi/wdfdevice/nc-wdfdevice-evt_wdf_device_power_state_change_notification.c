EVT_WDF_DEVICE_POWER_STATE_CHANGE_NOTIFICATION EvtWdfDevicePowerStateChangeNotification;

VOID EvtWdfDevicePowerStateChangeNotification(
  [in] WDFDEVICE Device,
  [in] PCWDF_DEVICE_POWER_NOTIFICATION_DATA NotificationData
)
{...}