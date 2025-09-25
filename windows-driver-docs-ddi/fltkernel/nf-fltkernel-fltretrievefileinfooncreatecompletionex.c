NTSTATUS FLTAPI FltRetrieveFileInfoOnCreateCompletionEx(
  [in]  PFLT_FILTER        Filter,
  [in]  PFLT_CALLBACK_DATA Data,
  [in]  ULONG              InfoClass,
  [out] PULONG             RetInfoSize,
  [out] PVOID              *RetInfoBuffer
);