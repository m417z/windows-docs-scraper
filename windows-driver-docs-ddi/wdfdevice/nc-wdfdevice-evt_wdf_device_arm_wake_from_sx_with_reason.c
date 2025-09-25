EVT_WDF_DEVICE_ARM_WAKE_FROM_SX_WITH_REASON EvtWdfDeviceArmWakeFromSxWithReason;

NTSTATUS EvtWdfDeviceArmWakeFromSxWithReason(
  [in] WDFDEVICE Device,
  [in] BOOLEAN DeviceWakeEnabled,
  [in] BOOLEAN ChildrenArmedForWake
)
{...}