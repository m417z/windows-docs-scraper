NTSTATUS FsRtlFastUnlockSingle(
  [in]           PFILE_LOCK     FileLock,
  [in]           PFILE_OBJECT   FileObject,
  [in]           LARGE_INTEGER  *FileOffset,
  [in]           PLARGE_INTEGER Length,
  [in]           PEPROCESS      ProcessId,
  [in]           ULONG          Key,
  [in, optional] PVOID          Context,
  [in]           BOOLEAN        AlreadySynchronized
);