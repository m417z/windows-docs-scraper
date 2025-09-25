typedef enum _WDF_IO_QUEUE_DISPATCH_TYPE {
  WdfIoQueueDispatchInvalid = 0,
  WdfIoQueueDispatchSequential,
  WdfIoQueueDispatchParallel,
  WdfIoQueueDispatchManual,
  WdfIoQueueDispatchMax
} WDF_IO_QUEUE_DISPATCH_TYPE;