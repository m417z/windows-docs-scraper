NDIS_WDI_TX_SEND_COMPLETE_IND NdisWdiTxSendCompleteInd;

void NdisWdiTxSendCompleteInd(
  NDIS_HANDLE NdisMiniportDataPathHandle,
  WDI_TX_FRAME_STATUS WifiTxFrameStatus,
  UINT16 NumCompletedSends,
  WDI_FRAME_ID *WifiTxFrameIdList,
  WDI_TX_COMPLETE_DATA *WifiTxCompleteList
)
{...}