EVT_UDECX_USB_DEVICE_ENDPOINTS_CONFIGURE EvtUdecxUsbDeviceEndpointsConfigure;

VOID EvtUdecxUsbDeviceEndpointsConfigure(
  [in] UDECXUSBDEVICE UdecxUsbDevice,
  [in] WDFREQUEST Request,
  [in] PUDECX_ENDPOINTS_CONFIGURE_PARAMS Params
)
{...}