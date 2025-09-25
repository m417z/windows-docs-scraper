MINIPORT_WDI_TX_ABORT MiniportWdiTxAbort;

void MiniportWdiTxAbort(
  TAL_TXRX_HANDLE MiniportTalTxRxContext,
  WDI_PORT_ID PortId,
  WDI_PEER_ID PeerId,
  NDIS_STATUS *pWifiStatus
)
{...}