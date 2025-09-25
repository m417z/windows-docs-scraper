EVT_WDF_REQUEST_IMPERSONATE EvtWdfRequestImpersonate;

VOID EvtWdfRequestImpersonate(
  [in]           WDFREQUEST Request,
  [in, optional] PVOID Context
)
{...}