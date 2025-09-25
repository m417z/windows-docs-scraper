EVT_WDF_DEVICE_POWER_POLICY_STATE_CHANGE_NOTIFICATION EvtWdfDevicePowerPolicyStateChangeNotification;

VOID EvtWdfDevicePowerPolicyStateChangeNotification(
  [in] WDFDEVICE Device,
  [in] PCWDF_DEVICE_POWER_POLICY_NOTIFICATION_DATA NotificationData
)
{...}