EVT_WDF_IO_QUEUE_IO_INTERNAL_DEVICE_CONTROL EvtWdfIoQueueIoInternalDeviceControl;

VOID EvtWdfIoQueueIoInternalDeviceControl(
  [in] WDFQUEUE Queue,
  [in] WDFREQUEST Request,
  [in] size_t OutputBufferLength,
  [in] size_t InputBufferLength,
  [in] ULONG IoControlCode
)
{...}