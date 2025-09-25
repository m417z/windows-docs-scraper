NTSTATUS FLTAPI FltQueryQuotaInformationFile(
  [in]            PFLT_INSTANCE    Instance,
  [in]            PFILE_OBJECT     FileObject,
  [out]           PIO_STATUS_BLOCK IoStatusBlock,
  [out]           PVOID            Buffer,
  [in]            ULONG            Length,
  [in]            BOOLEAN          ReturnSingleEntry,
  [in, optional]  PVOID            SidList,
  [in]            ULONG            SidListLength,
  [in, optional]  PULONG           StartSid,
  [in]            BOOLEAN          RestartScan,
  [out, optional] PULONG           LengthReturned
);