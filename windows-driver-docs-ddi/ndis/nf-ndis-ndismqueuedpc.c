ULONG NdisMQueueDpc(
  [in]           NDIS_HANDLE NdisInterruptHandle,
  [in]           ULONG       MessageId,
  [in]           ULONG       TargetProcessors,
  [in, optional] PVOID       MiniportDpcContext
);