NDIS_WDI_TX_SEND_RESTART_IND NdisWdiTxSendRestartInd;

void NdisWdiTxSendRestartInd(
  NDIS_HANDLE NdisMiniportDataPathHandle,
  WDI_PORT_ID PortId,
  WDI_PEER_ID PeerId,
  UINT32 ExTidBitmask,
  WDI_TX_PAUSE_REASON TxRestartReason
)
{...}