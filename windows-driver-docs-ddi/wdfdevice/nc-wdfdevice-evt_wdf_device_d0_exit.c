EVT_WDF_DEVICE_D0_EXIT EvtWdfDeviceD0Exit;

NTSTATUS EvtWdfDeviceD0Exit(
  [in] WDFDEVICE Device,
  [in] WDF_POWER_DEVICE_STATE TargetState
)
{...}