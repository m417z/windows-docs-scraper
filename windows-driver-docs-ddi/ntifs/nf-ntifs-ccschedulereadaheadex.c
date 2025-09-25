VOID CcScheduleReadAheadEx(
  [in] PFILE_OBJECT   FileObject,
  [in] PLARGE_INTEGER FileOffset,
  [in] ULONG          Length,
  [in] PETHREAD       IoIssuerThread
);