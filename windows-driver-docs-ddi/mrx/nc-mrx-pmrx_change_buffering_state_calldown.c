PMRX_CHANGE_BUFFERING_STATE_CALLDOWN PmrxChangeBufferingStateCalldown;

NTSTATUS PmrxChangeBufferingStateCalldown(
  [in, out] IN OUT PRX_CONTEXT RxContext,
  [in, out] IN OUT PMRX_SRV_OPEN SrvOpen,
  [in]      IN PVOID MRxContext
)
{...}