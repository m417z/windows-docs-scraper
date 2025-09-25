BOOLEAN FsRtlFastCheckLockForRead(
  [in] PFILE_LOCK     FileLock,
  [in] PLARGE_INTEGER StartingByte,
  [in] PLARGE_INTEGER Length,
  [in] ULONG          Key,
  [in] PFILE_OBJECT   FileObject,
  [in] PVOID          ProcessId
);