NTSTATUS FsRtlOplockBreakH(
  [in]           POPLOCK                       Oplock,
  [in]           PIRP                          Irp,
  [in]           ULONG                         Flags,
  [in, optional] PVOID                         Context,
  [in, optional] POPLOCK_WAIT_COMPLETE_ROUTINE CompletionRoutine,
  [in, optional] POPLOCK_FS_PREPOST_IRP        PostIrpRoutine
);