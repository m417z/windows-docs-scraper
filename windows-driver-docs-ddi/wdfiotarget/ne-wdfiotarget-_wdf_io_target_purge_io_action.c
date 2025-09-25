typedef enum _WDF_IO_TARGET_PURGE_IO_ACTION {
  WdfIoTargetPurgeIoUndefined = 0,
  WdfIoTargetPurgeIoAndWait = 1,
  WdfIoTargetPurgeIo = 2
} WDF_IO_TARGET_PURGE_IO_ACTION;