EVT_UDECX_USB_DEVICE_D0_EXIT EvtUdecxUsbDeviceD0Exit;

NTSTATUS EvtUdecxUsbDeviceD0Exit(
  [in] WDFDEVICE UdecxWdfDevice,
  [in] UDECXUSBDEVICE UdecxUsbDevice,
  [in] UDECX_USB_DEVICE_WAKE_SETTING WakeSetting
)
{...}