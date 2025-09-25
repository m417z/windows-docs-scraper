NDIS_WDI_TX_QUERY_RA_TID_STATE NdisWdiTxQueryRaTidState;

void NdisWdiTxQueryRaTidState(
  [in]  NDIS_HANDLE NdisMiniportDataPathHandle,
  [in]  WDI_PORT_ID PortId,
  [in]  WDI_PEER_ID PeerId,
  [in]  WDI_EXTENDED_TID ExTid,
  [out] NDIS_STATUS *pWifiStatus,
  [out] PUINT16 pQueueLength
)
{...}