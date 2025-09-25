NDIS_WDI_TX_SEND_RESTART_IND NdisWdiTxSendRestartInd;

void NdisWdiTxSendRestartInd(
  [in] NDIS_HANDLE NdisMiniportDataPathHandle,
  [in] WDI_PORT_ID PortId,
  [in] WDI_PEER_ID PeerId,
  [in] UINT32 ExTidBitmask,
  [in] WDI_TX_PAUSE_REASON TxRestartReason
)
{...}