PVOID FLTAPI FltRetrieveFileInfoOnCreateCompletion(
  [in]  PFLT_FILTER        Filter,
  [in]  PFLT_CALLBACK_DATA Data,
  [in]  ULONG              InfoClass,
  [out] PULONG             Size
);