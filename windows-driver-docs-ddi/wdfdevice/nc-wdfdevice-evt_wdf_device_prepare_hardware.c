EVT_WDF_DEVICE_PREPARE_HARDWARE EvtWdfDevicePrepareHardware;

NTSTATUS EvtWdfDevicePrepareHardware(
  [in] WDFDEVICE Device,
  [in] WDFCMRESLIST ResourcesRaw,
  [in] WDFCMRESLIST ResourcesTranslated
)
{...}