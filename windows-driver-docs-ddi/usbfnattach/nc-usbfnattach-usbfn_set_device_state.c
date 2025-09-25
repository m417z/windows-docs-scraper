USBFN_SET_DEVICE_STATE UsbfnSetDeviceState;

NTSTATUS UsbfnSetDeviceState(
  [in] PVOID Context,
  [in] USBFN_DEVICE_STATE DeviceState,
  [in] USBFN_BUS_SPEED BusSpeed
)
{...}