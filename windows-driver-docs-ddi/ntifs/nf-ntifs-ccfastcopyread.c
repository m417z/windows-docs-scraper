VOID CcFastCopyRead(
  [in]  PFILE_OBJECT     FileObject,
  [in]  ULONG            FileOffset,
  [in]  ULONG            Length,
  [in]  ULONG            PageCount,
  [out] PVOID            Buffer,
  [out] PIO_STATUS_BLOCK IoStatus
);