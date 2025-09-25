VOID CcPrepareMdlWrite(
  [in]  PFILE_OBJECT     FileObject,
  [in]  PLARGE_INTEGER   FileOffset,
  [in]  ULONG            Length,
  [out] PMDL             *MdlChain,
  [out] PIO_STATUS_BLOCK IoStatus
);