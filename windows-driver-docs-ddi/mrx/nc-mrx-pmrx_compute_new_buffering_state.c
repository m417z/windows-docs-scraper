PMRX_COMPUTE_NEW_BUFFERING_STATE PmrxComputeNewBufferingState;

NTSTATUS PmrxComputeNewBufferingState(
  [in, out] IN OUT PMRX_SRV_OPEN SrvOpen,
  [in]      IN PVOID MRxContext,
  [out]     OUT PULONG NewBufferingState
)
{...}