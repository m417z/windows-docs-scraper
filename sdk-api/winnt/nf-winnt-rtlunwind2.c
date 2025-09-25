NTSYSAPI VOID RtlUnwind2(
  [in, optional] FRAME_POINTERS    TargetFrame,
  [in, optional] PVOID             TargetIp,
  [in, optional] PEXCEPTION_RECORD ExceptionRecord,
  [in]           PVOID             ReturnValue,
  [in]           PCONTEXT          ContextRecord
);