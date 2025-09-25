NDIS_STATUS NdisMAllocateNetBufferSGList(
  [in]           NDIS_HANDLE NdisMiniportDmaHandle,
  [in]           PNET_BUFFER NetBuffer,
  [in]           PVOID       Context,
  [in]           ULONG       Flags,
  [in, optional] PVOID       ScatterGatherListBuffer,
  [in]           ULONG       ScatterGatherListBufferSize
);