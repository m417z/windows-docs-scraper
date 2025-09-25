MINIPORT_WDI_TX_ABORT MiniportWdiTxAbort;

void MiniportWdiTxAbort(
  [in]  TAL_TXRX_HANDLE MiniportTalTxRxContext,
  [in]  WDI_PORT_ID PortId,
  [in]  WDI_PEER_ID PeerId,
  [out] NDIS_STATUS *pWifiStatus
)
{...}