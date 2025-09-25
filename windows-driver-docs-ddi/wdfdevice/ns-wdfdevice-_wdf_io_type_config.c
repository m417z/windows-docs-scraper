typedef struct _WDF_IO_TYPE_CONFIG {
  ULONG              Size;
  WDF_DEVICE_IO_TYPE ReadWriteIoType;
  WDF_DEVICE_IO_TYPE DeviceControlIoType;
  ULONG              DirectTransferThreshold;
} WDF_IO_TYPE_CONFIG, *PWDF_IO_TYPE_CONFIG;