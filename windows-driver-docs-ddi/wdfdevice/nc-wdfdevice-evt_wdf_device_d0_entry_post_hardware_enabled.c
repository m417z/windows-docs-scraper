EVT_WDF_DEVICE_D0_ENTRY_POST_HARDWARE_ENABLED EvtWdfDeviceD0EntryPostHardwareEnabled;

NTSTATUS EvtWdfDeviceD0EntryPostHardwareEnabled(
  WDFDEVICE Device,
  WDF_POWER_DEVICE_STATE PreviousState
)
{...}