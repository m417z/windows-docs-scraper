BOOLEAN CcCopyReadEx(
  [in]  PFILE_OBJECT     FileObject,
  [in]  PLARGE_INTEGER   FileOffset,
  [in]  ULONG            Length,
  [in]  BOOLEAN          Wait,
  [out] PVOID            Buffer,
  [out] PIO_STATUS_BLOCK IoStatus,
  [in]  PETHREAD         IoIssuerThread
);