VOID FsRtlInitializeFileLock(
  [in]           PFILE_LOCK                 FileLock,
  [in, optional] PCOMPLETE_LOCK_IRP_ROUTINE CompleteLockIrpRoutine,
  [in, optional] PUNLOCK_ROUTINE            UnlockRoutine
);