NTSTATUS FsRtlCheckOplockEx2(
  [in]           POPLOCK                       Oplock,
  [in]           PIRP                          Irp,
  [in]           ULONG                         Flags,
  [in]           ULONG                         FlagsEx2,
  [in, optional] PVOID                         CompletionRoutineContext,
  [in, optional] POPLOCK_WAIT_COMPLETE_ROUTINE CompletionRoutine,
  [in, optional] POPLOCK_FS_PREPOST_IRP        PostIrpRoutine,
  [in]           ULONGLONG                     Timeout,
  [in, optional] PVOID                         NotifyContext,
  [in, optional] POPLOCK_NOTIFY_ROUTINE        NotifyRoutine
);