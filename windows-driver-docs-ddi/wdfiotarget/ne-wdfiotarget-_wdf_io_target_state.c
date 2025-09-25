typedef enum _WDF_IO_TARGET_STATE {
  WdfIoTargetStateUndefined = 0,
  WdfIoTargetStarted,
  WdfIoTargetStopped,
  WdfIoTargetClosedForQueryRemove,
  WdfIoTargetClosed,
  WdfIoTargetDeleted,
  WdfIoTargetPurged
} WDF_IO_TARGET_STATE, *PWDF_IO_TARGET_STATE;