NTSYSAPI VOID RtlUnwind(
  [in, optional] PVOID             TargetFrame,
  [in, optional] PVOID             TargetIp,
  [in, optional] PEXCEPTION_RECORD ExceptionRecord,
  [in]           PVOID             ReturnValue
);