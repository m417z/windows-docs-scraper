VOID IoAllocateController(
  [in]           PCONTROLLER_OBJECT ControllerObject,
  [in]           PDEVICE_OBJECT     DeviceObject,
  [in]           PDRIVER_CONTROL    ExecutionRoutine,
  [in, optional] PVOID              Context
);