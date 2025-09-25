BOOLEAN CcCopyWrite(
  [in] PFILE_OBJECT   FileObject,
  [in] PLARGE_INTEGER FileOffset,
  [in] ULONG          Length,
  [in] BOOLEAN        Wait,
  [in] PVOID          Buffer
);