EVT_UCX_USBDEVICE_ENDPOINT_ADD EvtUcxUsbdeviceEndpointAdd;

NTSTATUS EvtUcxUsbdeviceEndpointAdd(
  [in]           UCXCONTROLLER UcxController,
  [in]           UCXUSBDEVICE UcxUsbDevice,
  [in]           PUSB_ENDPOINT_DESCRIPTOR UsbEndpointDescriptor,
  [in]           ULONG UsbEndpointDescriptorBufferLength,
  [in, optional] PUSB_SUPERSPEED_ENDPOINT_COMPANION_DESCRIPTOR SuperSpeedEndpointCompanionDescriptor,
  [in]           PUCXENDPOINT_INIT UcxEndpointInit
)
{...}