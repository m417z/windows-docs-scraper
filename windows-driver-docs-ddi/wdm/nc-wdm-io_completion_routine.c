IO_COMPLETION_ROUTINE IoCompletionRoutine;

NTSTATUS IoCompletionRoutine(
  [in]           PDEVICE_OBJECT DeviceObject,
  [in]           PIRP Irp,
  [in, optional] PVOID Context
)
{...}