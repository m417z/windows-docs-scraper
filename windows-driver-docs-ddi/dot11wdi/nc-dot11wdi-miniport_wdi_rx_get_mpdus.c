MINIPORT_WDI_RX_GET_MPDUS MiniportWdiRxGetMpdus;

void MiniportWdiRxGetMpdus(
  [in]  TAL_TXRX_HANDLE MiniportTalTxRxContext,
  [in]  WDI_PEER_ID PeerId,
  [in]  WDI_EXTENDED_TID ExTid,
  [out] PNET_BUFFER_LIST *ppNBL
)
{...}