NDIS_WDI_TX_TRANSFER_COMPLETE_IND NdisWdiTxTransferCompleteInd;

void NdisWdiTxTransferCompleteInd(
  [in] NDIS_HANDLE NdisMiniportDataPathHandle,
  [in] WDI_TX_FRAME_STATUS WifiTxFrameStatus,
  [in] PNET_BUFFER_LIST pNBL
)
{...}