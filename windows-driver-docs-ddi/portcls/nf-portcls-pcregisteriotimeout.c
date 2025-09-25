PORTCLASSAPI NTSTATUS PcRegisterIoTimeout(
  [in] PDEVICE_OBJECT    pDeviceObject,
  [in] PIO_TIMER_ROUTINE pTimerRoutine,
  [in] PVOID             pContext
);