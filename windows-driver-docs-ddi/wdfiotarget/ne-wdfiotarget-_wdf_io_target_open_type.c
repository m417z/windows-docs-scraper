typedef enum _WDF_IO_TARGET_OPEN_TYPE {
  WdfIoTargetOpenUndefined = 0,
  WdfIoTargetOpenUseExistingDevice = 1,
  WdfIoTargetOpenByName = 2,
  WdfIoTargetOpenReopen = 3,
  WdfIoTargetOpenLocalTargetByFile = 4
} WDF_IO_TARGET_OPEN_TYPE;