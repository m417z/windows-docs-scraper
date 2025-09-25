NDIS_WDI_TX_SEND_COMPLETE_IND NdisWdiTxSendCompleteInd;

void NdisWdiTxSendCompleteInd(
  [in]           NDIS_HANDLE NdisMiniportDataPathHandle,
  [in]           WDI_TX_FRAME_STATUS WifiTxFrameStatus,
  [in]           UINT16 NumCompletedSends,
  [in]           WDI_FRAME_ID *WifiTxFrameIdList,
  [in, optional] WDI_TX_COMPLETE_DATA *WifiTxCompleteList
)
{...}