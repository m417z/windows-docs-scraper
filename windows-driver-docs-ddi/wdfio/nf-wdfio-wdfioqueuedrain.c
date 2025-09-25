VOID WdfIoQueueDrain(
  [in]           WDFQUEUE               Queue,
  [in, optional] PFN_WDF_IO_QUEUE_STATE DrainComplete,
  [in, optional] WDFCONTEXT             Context
);