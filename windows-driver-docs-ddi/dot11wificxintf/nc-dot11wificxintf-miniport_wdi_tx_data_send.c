MINIPORT_WDI_TX_DATA_SEND MiniportWdiTxDataSend;

void MiniportWdiTxDataSend(
  TAL_TXRX_HANDLE MiniportTalTxRxContext,
  WDI_PORT_ID PortId,
  WDI_PEER_ID PeerId,
  WDI_EXTENDED_TID ExTid,
  UINT16 NumQueueFrames,
  UINT32 NumActiveFrames,
  BOOLEAN bRobustnessFlag
)
{...}