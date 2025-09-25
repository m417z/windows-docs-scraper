WDF_IO_QUEUE_STATE WdfIoQueueGetState(
  [in]            WDFQUEUE Queue,
  [out, optional] PULONG   QueueRequests,
  [out, optional] PULONG   DriverRequests
);