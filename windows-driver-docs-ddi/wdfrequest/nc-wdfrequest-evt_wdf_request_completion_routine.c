EVT_WDF_REQUEST_COMPLETION_ROUTINE EvtWdfRequestCompletionRoutine;

VOID EvtWdfRequestCompletionRoutine(
  [in] WDFREQUEST Request,
  [in] WDFIOTARGET Target,
  [in] PWDF_REQUEST_COMPLETION_PARAMS Params,
  [in] WDFCONTEXT Context
)
{...}