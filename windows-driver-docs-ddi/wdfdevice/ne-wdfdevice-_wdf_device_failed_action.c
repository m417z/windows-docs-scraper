typedef enum _WDF_DEVICE_FAILED_ACTION {
  WdfDeviceFailedUndefined = 0,
  WdfDeviceFailedAttemptRestart,
  WdfDeviceFailedNoRestart
} WDF_DEVICE_FAILED_ACTION;