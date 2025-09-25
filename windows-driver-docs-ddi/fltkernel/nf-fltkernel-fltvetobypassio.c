NTSTATUS FLTAPI FltVetoBypassIo(
  [in] PFLT_CALLBACK_DATA    CallbackData,
  [in] PCFLT_RELATED_OBJECTS FltObjects,
  [in] NTSTATUS              OperationStatus,
  [in] PCUNICODE_STRING      FailureReason
);