BOOLEAN FsRtlCopyWrite(
  [in]  PFILE_OBJECT     FileObject,
  [in]  PLARGE_INTEGER   FileOffset,
  [in]  ULONG            Length,
  [in]  BOOLEAN          Wait,
  [in]  ULONG            LockKey,
  [in]  PVOID            Buffer,
  [out] PIO_STATUS_BLOCK IoStatus,
  [in]  PDEVICE_OBJECT   DeviceObject
);