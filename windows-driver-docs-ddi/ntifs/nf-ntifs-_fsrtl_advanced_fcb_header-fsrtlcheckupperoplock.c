NTSTATUS FsRtlCheckUpperOplock(
  [in]           POPLOCK                       Oplock,
  [in]           ULONG                         NewLowerOplockState,
  [in, optional] PVOID                         CompletionRoutineContext,
  [in, optional] POPLOCK_WAIT_COMPLETE_ROUTINE CompletionRoutine,
                 POPLOCK_FS_PREPOST_IRP        PrePendRoutine,
  [in]           ULONG                         Flags
);