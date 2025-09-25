MINIPORT_WDI_RX_GET_MPDUS MiniportWdiRxGetMpdus;

void MiniportWdiRxGetMpdus(
  TAL_TXRX_HANDLE MiniportTalTxRxContext,
  WDI_PEER_ID PeerId,
  WDI_EXTENDED_TID ExTid,
  PNET_BUFFER_LIST *ppNBL
)
{...}