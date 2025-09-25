EVT_UCX_USBDEVICE_GET_CHARACTERISTIC EvtUcxUsbdeviceGetCharacteristic;

NTSTATUS EvtUcxUsbdeviceGetCharacteristic(
  [in]      UCXCONTROLLER UcxController,
  [in]      UCXUSBDEVICE UcxUsbDevice,
  [in, out] PUCX_USBDEVICE_CHARACTERISTIC UcxUsbDeviceCharacteristic
)
{...}