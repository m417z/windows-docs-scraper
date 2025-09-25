NTSTATUS FsRtlCheckOplock(
  [in]           POPLOCK                       Oplock,
  [in]           PIRP                          Irp,
  [in, optional] PVOID                         Context,
  [in, optional] POPLOCK_WAIT_COMPLETE_ROUTINE CompletionRoutine,
  [in, optional] POPLOCK_FS_PREPOST_IRP        PostIrpRoutine
);