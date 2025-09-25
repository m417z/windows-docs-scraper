MINIPORT_WDI_TX_DATA_SEND MiniportWdiTxDataSend;

void MiniportWdiTxDataSend(
  [in] TAL_TXRX_HANDLE MiniportTalTxRxContext,
  [in] WDI_PORT_ID PortId,
  [in] WDI_PEER_ID PeerId,
  [in] WDI_EXTENDED_TID ExTid,
  [in] UINT16 NumQueueFrames,
  [in] UINT32 NumActiveFrames,
  [in] BOOLEAN bRobustnessFlag
)
{...}