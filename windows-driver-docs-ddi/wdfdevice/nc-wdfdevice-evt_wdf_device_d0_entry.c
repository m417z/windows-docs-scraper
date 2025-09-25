EVT_WDF_DEVICE_D0_ENTRY EvtWdfDeviceD0Entry;

NTSTATUS EvtWdfDeviceD0Entry(
  [in] WDFDEVICE Device,
  [in] WDF_POWER_DEVICE_STATE PreviousState
)
{...}