MINIPORT_WDI_TX_TAL_SEND MiniportWdiTxTalSend;

void MiniportWdiTxTalSend(
  TAL_TXRX_HANDLE MiniportTalTxRxContext,
  WDI_PORT_ID PortId,
  WDI_PEER_ID PeerId,
  WDI_EXTENDED_TID ExTid,
  UINT16 NumQueueFrames,
  UINT32 NumActiveFrames,
  BOOLEAN bRobustnessFlag
)
{...}