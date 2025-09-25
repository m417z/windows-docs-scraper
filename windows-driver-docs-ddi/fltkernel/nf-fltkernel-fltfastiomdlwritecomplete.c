BOOLEAN FLTAPI FltFastIoMdlWriteComplete(
       PFLT_INSTANCE  InitiatingInstance,
  [in] PFILE_OBJECT   FileObject,
  [in] PLARGE_INTEGER FileOffset,
  [in] PMDL           MdlChain
);