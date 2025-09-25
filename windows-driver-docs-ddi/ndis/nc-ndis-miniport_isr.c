MINIPORT_ISR MiniportIsr;

BOOLEAN MiniportIsr(
  [in]  NDIS_HANDLE MiniportInterruptContext,
  [out] PBOOLEAN QueueDefaultInterruptDpc,
  [out] PULONG TargetProcessors
)
{...}