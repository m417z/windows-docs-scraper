NDIS_WDI_TX_DEQUEUE_IND NdisWdiTxDequeueInd;

void NdisWdiTxDequeueInd(
  [in]  NDIS_HANDLE NdisMiniportDataPathHandle,
  [in]  UINT32 Quantum,
  [in]  UINT8 MaxNumFrames,
  [in]  UINT16 Credit,
  [out] PNET_BUFFER_LIST *ppNBL
)
{...}