VOID WdfRequestSetCompletionRoutine(
  [in]           WDFREQUEST                         Request,
  [in, optional] PFN_WDF_REQUEST_COMPLETION_ROUTINE CompletionRoutine,
  [in, optional] __drv_aliasesMem WDFCONTEXT        CompletionContext
);