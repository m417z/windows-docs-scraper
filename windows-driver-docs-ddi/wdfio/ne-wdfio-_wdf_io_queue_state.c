typedef enum _WDF_IO_QUEUE_STATE {
  WdfIoQueueAcceptRequests = 0x01,
  WdfIoQueueDispatchRequests = 0x02,
  WdfIoQueueNoRequests = 0x04,
  WdfIoQueueDriverNoRequests = 0x08,
  WdfIoQueuePnpHeld = 0x10
} WDF_IO_QUEUE_STATE;