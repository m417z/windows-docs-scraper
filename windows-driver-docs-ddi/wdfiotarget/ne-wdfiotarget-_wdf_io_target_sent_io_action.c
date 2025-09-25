typedef enum _WDF_IO_TARGET_SENT_IO_ACTION {
  WdfIoTargetSentIoUndefined = 0,
  WdfIoTargetCancelSentIo,
  WdfIoTargetWaitForSentIoToComplete,
  WdfIoTargetLeaveSentIoPending
} WDF_IO_TARGET_SENT_IO_ACTION;