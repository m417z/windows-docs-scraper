EVT_UCX_USBDEVICE_DEFAULT_ENDPOINT_ADD EvtUcxUsbdeviceDefaultEndpointAdd;

NTSTATUS EvtUcxUsbdeviceDefaultEndpointAdd(
  [in] UCXCONTROLLER UcxController,
  [in] UCXUSBDEVICE UcxUsbDevice,
  [in] ULONG MaxPacketSize,
  [in] PUCXENDPOINT_INIT UcxEndpointInit
)
{...}