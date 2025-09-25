VOID CcDeferWrite(
  [in] PFILE_OBJECT            FileObject,
  [in] PCC_POST_DEFERRED_WRITE PostRoutine,
  [in] PVOID                   Context1,
  [in] PVOID                   Context2,
  [in] ULONG                   BytesToWrite,
  [in] BOOLEAN                 Retrying
);