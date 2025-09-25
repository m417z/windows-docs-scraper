typedef enum _WDF_IO_TARGET_STATE {
  WdfIoTargetStateUndefined,
  WdfIoTargetStarted,
  WdfIoTargetStopped,
  WdfIoTargetClosedForQueryRemove,
  WdfIoTargetClosed,
  WdfIoTargetDeleted,
  WdfIoTargetStateMaximum
} WDF_IO_TARGET_STATE, *PWDF_IO_TARGET_STATE;