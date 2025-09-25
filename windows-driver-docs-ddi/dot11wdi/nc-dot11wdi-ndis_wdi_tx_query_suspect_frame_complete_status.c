NDIS_WDI_TX_QUERY_SUSPECT_FRAME_COMPLETE_STATUS NdisWdiTxQuerySuspectFrameCompleteStatus;

void NdisWdiTxQuerySuspectFrameCompleteStatus(
  NDIS_HANDLE NdisMiniportDataPathHandle,
  UINT64 SuspectFrameContext,
  PNET_BUFFER_LIST pNBL,
  BOOLEAN *pIsTransferCompleteNeeded,
  BOOLEAN *pIsSendCompleteNeeded,
  NDIS_STATUS *pWifiStatus
)
{...}