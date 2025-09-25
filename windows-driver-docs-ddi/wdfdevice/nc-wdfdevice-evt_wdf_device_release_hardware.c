EVT_WDF_DEVICE_RELEASE_HARDWARE EvtWdfDeviceReleaseHardware;

NTSTATUS EvtWdfDeviceReleaseHardware(
  [in] WDFDEVICE Device,
  [in] WDFCMRESLIST ResourcesTranslated
)
{...}