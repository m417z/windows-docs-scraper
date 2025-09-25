EVT_WDF_DEVICE_D0_EXIT_PRE_INTERRUPTS_DISABLED EvtWdfDeviceD0ExitPreInterruptsDisabled;

NTSTATUS EvtWdfDeviceD0ExitPreInterruptsDisabled(
  [in] WDFDEVICE Device,
  [in] WDF_POWER_DEVICE_STATE TargetState
)
{...}