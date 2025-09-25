NTSTATUS IoSetCompletionRoutineEx(
  [in]           PDEVICE_OBJECT         DeviceObject,
  [in]           PIRP                   Irp,
  [in]           PIO_COMPLETION_ROUTINE CompletionRoutine,
  [in, optional] PVOID                  Context,
  [in]           BOOLEAN                InvokeOnSuccess,
  [in]           BOOLEAN                InvokeOnError,
  [in]           BOOLEAN                InvokeOnCancel
);