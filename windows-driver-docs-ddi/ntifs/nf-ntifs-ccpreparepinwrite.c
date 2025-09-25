BOOLEAN CcPreparePinWrite(
  [in]  PFILE_OBJECT   FileObject,
  [in]  PLARGE_INTEGER FileOffset,
  [in]  ULONG          Length,
  [in]  BOOLEAN        Zero,
  [in]  ULONG          Flags,
  [out] PVOID          *Bcb,
  [out] PVOID          *Buffer
);