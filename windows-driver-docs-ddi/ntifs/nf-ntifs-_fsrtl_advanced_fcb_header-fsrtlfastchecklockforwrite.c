BOOLEAN FsRtlFastCheckLockForWrite(
  [in] PFILE_LOCK     FileLock,
  [in] PLARGE_INTEGER StartingByte,
  [in] PLARGE_INTEGER Length,
  [in] ULONG          Key,
  [in] PVOID          FileObject,
  [in] PVOID          ProcessId
);