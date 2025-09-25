EVT_WDF_DRIVER_DEVICE_ADD EvtWdfDriverDeviceAdd;

NTSTATUS EvtWdfDriverDeviceAdd(
  [in]      WDFDRIVER Driver,
  [in, out] PWDFDEVICE_INIT DeviceInit
)
{...}