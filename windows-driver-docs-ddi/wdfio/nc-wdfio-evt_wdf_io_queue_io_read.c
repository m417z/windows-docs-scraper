EVT_WDF_IO_QUEUE_IO_READ EvtWdfIoQueueIoRead;

VOID EvtWdfIoQueueIoRead(
  [in] WDFQUEUE Queue,
  [in] WDFREQUEST Request,
  [in] size_t Length
)
{...}