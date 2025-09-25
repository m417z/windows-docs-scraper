typedef enum _WDF_DEVICE_IO_TYPE {
  WdfDeviceIoUndefined,
  WdfDeviceIoNeither,
  WdfDeviceIoBuffered,
  WdfDeviceIoDirect,
  WdfDeviceIoBufferedOrDirect,
  WdfDeviceIoMaximum
} WDF_DEVICE_IO_TYPE, *PWDF_DEVICE_IO_TYPE;