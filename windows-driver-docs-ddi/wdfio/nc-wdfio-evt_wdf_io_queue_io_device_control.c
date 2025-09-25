EVT_WDF_IO_QUEUE_IO_DEVICE_CONTROL EvtWdfIoQueueIoDeviceControl;

VOID EvtWdfIoQueueIoDeviceControl(
  [in] WDFQUEUE Queue,
  [in] WDFREQUEST Request,
  [in] size_t OutputBufferLength,
  [in] size_t InputBufferLength,
  [in] ULONG IoControlCode
)
{...}