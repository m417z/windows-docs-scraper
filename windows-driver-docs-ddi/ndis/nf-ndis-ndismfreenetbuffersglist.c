VOID NdisMFreeNetBufferSGList(
  [in] NDIS_HANDLE          NdisMiniportDmaHandle,
  [in] PSCATTER_GATHER_LIST pSGL,
  [in] PNET_BUFFER          NetBuffer
);