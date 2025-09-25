NTSTATUS FLTAPI FltIsIoRedirectionAllowedForOperation(
  [in]            PFLT_CALLBACK_DATA Data,
  [in]            PFLT_INSTANCE      TargetInstance,
  [out]           PBOOLEAN           RedirectionAllowedThisIo,
  [out, optional] PBOOLEAN           RedirectionAllowedAllIo
);