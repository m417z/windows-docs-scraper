NTSTATUS FsRtlFastUnlockAllByKey(
  [in]           PFILE_LOCK   FileLock,
  [in]           PFILE_OBJECT FileObject,
  [in]           PEPROCESS    ProcessId,
  [in]           ULONG        Key,
  [in, optional] PVOID        Context
);