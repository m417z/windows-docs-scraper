EVT_UCX_CONTROLLER_USBDEVICE_ADD EvtUcxControllerUsbdeviceAdd;

NTSTATUS EvtUcxControllerUsbdeviceAdd(
  [in] UCXCONTROLLER UcxController,
  [in] PUCXUSBDEVICE_INFO UcxUsbDeviceInfo,
  [in] PUCXUSBDEVICE_INIT UsbDeviceInit
)
{...}