MINIPORT_WDI_TX_PEER_BACKLOG MiniportWdiTxPeerBacklog;

void MiniportWdiTxPeerBacklog(
  [in] TAL_TXRX_HANDLE MiniportTalTxRxContext,
  [in] WDI_PORT_ID PortId,
  [in] WDI_PEER_ID PeerId,
  [in] BOOLEAN bBacklogged
)
{...}