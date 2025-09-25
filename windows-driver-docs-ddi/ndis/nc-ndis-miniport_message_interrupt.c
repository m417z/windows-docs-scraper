MINIPORT_MESSAGE_INTERRUPT MiniportMessageInterrupt;

BOOLEAN MiniportMessageInterrupt(
  [in]  NDIS_HANDLE MiniportInterruptContext,
  [in]  ULONG MessageId,
  [out] PBOOLEAN QueueDefaultInterruptDpc,
  [out] PULONG TargetProcessors
)
{...}