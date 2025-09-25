NTSTATUS FsRtlOplockBreakToNone(
  POPLOCK                       Oplock,
  PIO_STACK_LOCATION            IrpSp,
  PIRP                          Irp,
  PVOID                         Context,
  POPLOCK_WAIT_COMPLETE_ROUTINE CompletionRoutine,
  POPLOCK_FS_PREPOST_IRP        PostIrpRoutine
);