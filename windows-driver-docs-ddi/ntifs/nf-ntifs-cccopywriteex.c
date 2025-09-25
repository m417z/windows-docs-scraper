BOOLEAN CcCopyWriteEx(
  [in] PFILE_OBJECT   FileObject,
  [in] PLARGE_INTEGER FileOffset,
  [in] ULONG          Length,
  [in] BOOLEAN        Wait,
  [in] PVOID          Buffer,
  [in] PETHREAD       IoIssuerThread
);