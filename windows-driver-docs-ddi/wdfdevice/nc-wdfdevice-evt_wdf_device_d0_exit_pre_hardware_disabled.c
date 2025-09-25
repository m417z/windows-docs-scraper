EVT_WDF_DEVICE_D0_EXIT_PRE_HARDWARE_DISABLED EvtWdfDeviceD0ExitPreHardwareDisabled;

NTSTATUS EvtWdfDeviceD0ExitPreHardwareDisabled(
  WDFDEVICE Device,
  WDF_POWER_DEVICE_STATE TargetState
)
{...}