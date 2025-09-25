NTSTATUS FsRtlFastUnlockAll(
  [in]           PFILE_LOCK   FileLock,
  [in]           PFILE_OBJECT FileObject,
  [in]           PEPROCESS    ProcessId,
  [in, optional] PVOID        Context
);