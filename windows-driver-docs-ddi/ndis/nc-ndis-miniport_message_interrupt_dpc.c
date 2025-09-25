MINIPORT_MESSAGE_INTERRUPT_DPC MiniportMessageInterruptDpc;

VOID MiniportMessageInterruptDpc(
  [in] NDIS_HANDLE MiniportInterruptContext,
  [in] ULONG MessageId,
  [in] PVOID MiniportDpcContext,
  [in] PVOID ReceiveThrottleParameters,
       PVOID NdisReserved2 PULONG NdisReserved1,
  [in] PULONG NdisReserved2
)
{...}