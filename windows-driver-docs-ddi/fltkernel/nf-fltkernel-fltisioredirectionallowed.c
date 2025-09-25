NTSTATUS FLTAPI FltIsIoRedirectionAllowed(
  [in]  PFLT_INSTANCE SourceInstance,
  [in]  PFLT_INSTANCE TargetInstance,
  [out] PBOOLEAN      RedirectionAllowed
);