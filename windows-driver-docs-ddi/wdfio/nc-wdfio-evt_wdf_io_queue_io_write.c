EVT_WDF_IO_QUEUE_IO_WRITE EvtWdfIoQueueIoWrite;

VOID EvtWdfIoQueueIoWrite(
  [in] WDFQUEUE Queue,
  [in] WDFREQUEST Request,
  [in] size_t Length
)
{...}