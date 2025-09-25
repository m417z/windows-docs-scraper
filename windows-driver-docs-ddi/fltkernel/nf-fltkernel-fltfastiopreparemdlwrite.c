BOOLEAN FLTAPI FltFastIoPrepareMdlWrite(
        PFLT_INSTANCE    InitiatingInstance,
  [in]  PFILE_OBJECT     FileObject,
  [in]  PLARGE_INTEGER   FileOffset,
  [in]  ULONG            Length,
  [in]  ULONG            LockKey,
  [out] PMDL             *MdlChain,
  [out] PIO_STATUS_BLOCK IoStatus
);