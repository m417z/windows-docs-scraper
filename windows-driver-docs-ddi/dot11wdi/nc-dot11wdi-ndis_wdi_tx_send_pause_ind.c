NDIS_WDI_TX_SEND_PAUSE_IND NdisWdiTxSendPauseInd;

void NdisWdiTxSendPauseInd(
  [in] NDIS_HANDLE NdisMiniportDataPathHandle,
  [in] WDI_PORT_ID PortId,
  [in] WDI_PEER_ID PeerId,
  [in] UINT32 ExTidBitmask,
  [in] WDI_TX_PAUSE_REASON TxPauseReason
)
{...}