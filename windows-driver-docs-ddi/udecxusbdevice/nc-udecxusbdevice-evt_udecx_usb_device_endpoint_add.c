EVT_UDECX_USB_DEVICE_ENDPOINT_ADD EvtUdecxUsbDeviceEndpointAdd;

NTSTATUS EvtUdecxUsbDeviceEndpointAdd(
  [in] UDECXUSBDEVICE UdecxUsbDevice,
  [in] PUDECX_USB_ENDPOINT_INIT_AND_METADATA EndpointToCreate
)
{...}