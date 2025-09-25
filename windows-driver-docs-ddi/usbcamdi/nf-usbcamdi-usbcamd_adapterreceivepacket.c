PVOID USBCAMD_AdapterReceivePacket(
  [in] PHW_STREAM_REQUEST_BLOCK Srb,
  [in] PUSBCAMD_DEVICE_DATA     DeviceData,
  [in] PDEVICE_OBJECT           *DeviceObject,
  [in] BOOLEAN                  NeedsCompletion
);