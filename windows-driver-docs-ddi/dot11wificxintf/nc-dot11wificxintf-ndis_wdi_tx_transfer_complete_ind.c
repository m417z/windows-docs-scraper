NDIS_WDI_TX_TRANSFER_COMPLETE_IND NdisWdiTxTransferCompleteInd;

void NdisWdiTxTransferCompleteInd(
  NDIS_HANDLE NdisMiniportDataPathHandle,
  WDI_TX_FRAME_STATUS WifiTxFrameStatus,
  PNET_BUFFER_LIST pNBL
)
{...}