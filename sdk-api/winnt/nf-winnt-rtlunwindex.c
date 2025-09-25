NTSYSAPI VOID RtlUnwindEx(
  [in, optional] PVOID                 TargetFrame,
  [in, optional] PVOID                 TargetIp,
  [in, optional] PEXCEPTION_RECORD     ExceptionRecord,
  [in]           PVOID                 ReturnValue,
  [in]           PCONTEXT              ContextRecord,
  [in, optional] PUNWIND_HISTORY_TABLE HistoryTable
);