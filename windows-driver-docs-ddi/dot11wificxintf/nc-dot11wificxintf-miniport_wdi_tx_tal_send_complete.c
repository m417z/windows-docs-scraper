MINIPORT_WDI_TX_TAL_SEND_COMPLETE MiniportWdiTxTalSendComplete;

void MiniportWdiTxTalSendComplete(
  TAL_TXRX_HANDLE MiniportTalTxRxContext,
  PNET_BUFFER_LIST pNBL,
  WDI_TX_FRAME_STATUS TxFrameStatus
)
{...}