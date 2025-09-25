BOOLEAN FsRtlPrivateLock(
  PFILE_LOCK             FileLock,
  PFILE_OBJECT           FileObject,
  PLARGE_INTEGER         FileOffset,
  PLARGE_INTEGER         Length,
  PEPROCESS              ProcessId,
  ULONG                  Key,
  BOOLEAN                FailImmediately,
  BOOLEAN                ExclusiveLock,
  PIO_STATUS_BLOCK       Iosb,
  PIRP                   Irp,
  __drv_aliasesMem PVOID Context,
  BOOLEAN                AlreadySynchronized
);