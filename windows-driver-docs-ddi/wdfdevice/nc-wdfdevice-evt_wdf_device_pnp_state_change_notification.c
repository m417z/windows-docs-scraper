EVT_WDF_DEVICE_PNP_STATE_CHANGE_NOTIFICATION EvtWdfDevicePnpStateChangeNotification;

VOID EvtWdfDevicePnpStateChangeNotification(
  [in] WDFDEVICE Device,
  [in] PCWDF_DEVICE_PNP_NOTIFICATION_DATA NotificationData
)
{...}