EVT_WDF_DEVICE_REMOVE_ADDED_RESOURCES EvtWdfDeviceRemoveAddedResources;

NTSTATUS EvtWdfDeviceRemoveAddedResources(
  [in] WDFDEVICE Device,
  [in] WDFCMRESLIST ResourcesRaw,
  [in] WDFCMRESLIST ResourcesTranslated
)
{...}