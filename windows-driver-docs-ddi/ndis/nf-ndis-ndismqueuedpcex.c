KAFFINITY NdisMQueueDpcEx(
  [in] IN NDIS_HANDLE     NdisInterruptHandle,
  [in] IN ULONG           MessageId,
  [in] IN PGROUP_AFFINITY TargetProcessors,
  [in] IN PVOID           MiniportDpcContext
);