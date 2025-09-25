NTSTATUS FLTAPI FltQueryEaFile(
  [in]            PFLT_INSTANCE Instance,
  [in]            PFILE_OBJECT  FileObject,
  [out]           PVOID         ReturnedEaData,
  [in]            ULONG         Length,
  [in]            BOOLEAN       ReturnSingleEntry,
  [in, optional]  PVOID         EaList,
  [in]            ULONG         EaListLength,
  [in, optional]  PULONG        EaIndex,
  [in]            BOOLEAN       RestartScan,
  [out, optional] PULONG        LengthReturned
);