EVT_WDF_DEVICE_ENABLE_WAKE_AT_BUS EvtWdfDeviceEnableWakeAtBus;

NTSTATUS EvtWdfDeviceEnableWakeAtBus(
  [in] WDFDEVICE Device,
  [in] SYSTEM_POWER_STATE PowerState
)
{...}