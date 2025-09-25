BOOLEAN FLTAPI FltDoCompletionProcessingWhenSafe(
  [in]           PFLT_CALLBACK_DATA           Data,
  [in]           PCFLT_RELATED_OBJECTS        FltObjects,
  [in, optional] PVOID                        CompletionContext,
  [in]           FLT_POST_OPERATION_FLAGS     Flags,
  [in]           PFLT_POST_OPERATION_CALLBACK SafePostCallback,
  [out]          PFLT_POSTOP_CALLBACK_STATUS  RetPostOperationStatus
);