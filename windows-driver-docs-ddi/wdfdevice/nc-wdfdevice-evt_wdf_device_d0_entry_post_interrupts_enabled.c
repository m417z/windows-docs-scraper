EVT_WDF_DEVICE_D0_ENTRY_POST_INTERRUPTS_ENABLED EvtWdfDeviceD0EntryPostInterruptsEnabled;

NTSTATUS EvtWdfDeviceD0EntryPostInterruptsEnabled(
  [in] WDFDEVICE Device,
  [in] WDF_POWER_DEVICE_STATE PreviousState
)
{...}