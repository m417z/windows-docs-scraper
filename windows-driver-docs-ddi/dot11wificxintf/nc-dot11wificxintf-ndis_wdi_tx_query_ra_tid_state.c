NDIS_WDI_TX_QUERY_RA_TID_STATE NdisWdiTxQueryRaTidState;

void NdisWdiTxQueryRaTidState(
  NDIS_HANDLE NdisMiniportDataPathHandle,
  WDI_PORT_ID PortId,
  WDI_PEER_ID PeerId,
  WDI_EXTENDED_TID ExTid,
  NDIS_STATUS *pWifiStatus,
  PUINT16 pQueueLength
)
{...}