VOID IoSetCompletionRoutine(
  [in]           PIRP                   Irp,
  [in, optional] PIO_COMPLETION_ROUTINE CompletionRoutine,
  [in, optional] __drv_aliasesMem PVOID Context,
  [in]           BOOLEAN                InvokeOnSuccess,
  [in]           BOOLEAN                InvokeOnError,
  [in]           BOOLEAN                InvokeOnCancel
);