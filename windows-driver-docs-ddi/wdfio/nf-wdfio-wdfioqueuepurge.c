VOID WdfIoQueuePurge(
  [in]           WDFQUEUE               Queue,
  [in, optional] PFN_WDF_IO_QUEUE_STATE PurgeComplete,
  [in, optional] WDFCONTEXT             Context
);