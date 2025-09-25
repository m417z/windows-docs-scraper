VOID WdfIoQueueStop(
  [in]           WDFQUEUE               Queue,
  [in, optional] PFN_WDF_IO_QUEUE_STATE StopComplete,
  [in, optional] WDFCONTEXT             Context
);