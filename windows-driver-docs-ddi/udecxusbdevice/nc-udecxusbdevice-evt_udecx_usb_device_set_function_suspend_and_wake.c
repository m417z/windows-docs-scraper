EVT_UDECX_USB_DEVICE_SET_FUNCTION_SUSPEND_AND_WAKE EvtUdecxUsbDeviceSetFunctionSuspendAndWake;

NTSTATUS EvtUdecxUsbDeviceSetFunctionSuspendAndWake(
  [in] WDFDEVICE UdecxWdfDevice,
  [in] UDECXUSBDEVICE UdecxUsbDevice,
  [in] ULONG Interface,
  [in] UDECX_USB_DEVICE_FUNCTION_POWER FunctionPower
)
{...}