VOID WdfIoQueueStopAndPurge(
  [in]           WDFQUEUE               Queue,
  [in, optional] PFN_WDF_IO_QUEUE_STATE StopAndPurgeComplete,
  [in, optional] WDFCONTEXT             Context
);