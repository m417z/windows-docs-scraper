typedef enum _WDF_DEVICE_IO_TYPE {
  WdfDeviceIoUndefined = 0,
  WdfDeviceIoNeither,
  WdfDeviceIoBuffered,
  WdfDeviceIoDirect,
  WdfDeviceIoBufferedOrDirect = 4,
  WdfDeviceIoMaximum
} WDF_DEVICE_IO_TYPE, *PWDF_DEVICE_IO_TYPE;