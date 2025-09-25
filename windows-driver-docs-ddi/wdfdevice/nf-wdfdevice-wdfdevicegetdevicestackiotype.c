VOID WdfDeviceGetDeviceStackIoType(
  [in]  WDFDEVICE          Device,
  [out] WDF_DEVICE_IO_TYPE *ReadWriteIoType,
  [out] WDF_DEVICE_IO_TYPE *IoControlIoType
);