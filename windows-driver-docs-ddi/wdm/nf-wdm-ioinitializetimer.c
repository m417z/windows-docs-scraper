NTSTATUS IoInitializeTimer(
  [in]           PDEVICE_OBJECT         DeviceObject,
  [in]           PIO_TIMER_ROUTINE      TimerRoutine,
  [in, optional] __drv_aliasesMem PVOID Context
);