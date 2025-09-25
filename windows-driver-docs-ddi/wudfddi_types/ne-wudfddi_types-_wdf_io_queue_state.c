typedef enum _WDF_IO_QUEUE_STATE {
  WdfIoQueueAcceptRequests,
  WdfIoQueueDispatchRequests,
  WdfIoQueueNoRequests,
  WdfIoQueueDriverNoRequests,
  WdfIoQueuePnpHeld
} WDF_IO_QUEUE_STATE, *PWDF_IO_QUEUE_STATE;