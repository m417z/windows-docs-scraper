typedef enum _WDF_IO_TARGET_SENT_IO_ACTION {
  WdfIoTargetSentIoUndefined,
  WdfIoTargetCancelSentIo,
  WdfIoTargetWaitForSentIoToComplete,
  WdfIoTargetLeaveSentIoPending,
  WdfIoTargetSentIoMaximum
} WDF_IO_TARGET_SENT_IO_ACTION;