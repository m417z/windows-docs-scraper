EVT_WDF_IO_QUEUE_IO_STOP EvtWdfIoQueueIoStop;

VOID EvtWdfIoQueueIoStop(
  [in] WDFQUEUE Queue,
  [in] WDFREQUEST Request,
  [in] ULONG ActionFlags
)
{...}