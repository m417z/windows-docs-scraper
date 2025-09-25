typedef enum _WDF_TASK_QUEUE_DISPATCH_TYPE {
  WdfTaskQueueDispatchInvalid = 0,
  WdfTaskQueueDispatchSequential,
  WdfTaskQueueDispatchParallel,
  WdfTaskQueueDispatchMax
} WDF_TASK_QUEUE_DISPATCH_TYPE;