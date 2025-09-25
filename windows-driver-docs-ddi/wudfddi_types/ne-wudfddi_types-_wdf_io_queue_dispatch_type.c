typedef enum _WDF_IO_QUEUE_DISPATCH_TYPE {
  WdfIoQueueDispatchSequential,
  WdfIoQueueDispatchParallel,
  WdfIoQueueDispatchManual,
  WdfIoQueueDispatchMaximum
} WDF_IO_QUEUE_DISPATCH_TYPE;