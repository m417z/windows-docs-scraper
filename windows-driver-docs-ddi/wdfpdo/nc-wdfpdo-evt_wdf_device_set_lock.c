EVT_WDF_DEVICE_SET_LOCK EvtWdfDeviceSetLock;

NTSTATUS EvtWdfDeviceSetLock(
  [in] WDFDEVICE Device,
  [in] BOOLEAN IsLocked
)
{...}