NDIS_WDI_TX_DEQUEUE_IND NdisWdiTxDequeueInd;

void NdisWdiTxDequeueInd(
  NDIS_HANDLE NdisMiniportDataPathHandle,
  UINT32 Quantum,
  UINT8 MaxNumFrames,
  UINT16 Credit,
  PNET_BUFFER_LIST *ppNBL
)
{...}