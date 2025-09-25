MINIPORT_WDI_TX_TAL_SEND_COMPLETE MiniportWdiTxTalSendComplete;

void MiniportWdiTxTalSendComplete(
  [in] TAL_TXRX_HANDLE MiniportTalTxRxContext,
  [in] PNET_BUFFER_LIST pNBL,
  [in] WDI_TX_FRAME_STATUS TxFrameStatus
)
{...}