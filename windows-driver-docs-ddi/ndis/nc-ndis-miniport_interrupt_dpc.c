MINIPORT_INTERRUPT_DPC MiniportInterruptDpc;

VOID MiniportInterruptDpc(
  [in] NDIS_HANDLE MiniportInterruptContext,
  [in] PVOID MiniportDpcContext,
  [in] PVOID ReceiveThrottleParameters,
  [in] PVOID NdisReserved2
)
{...}