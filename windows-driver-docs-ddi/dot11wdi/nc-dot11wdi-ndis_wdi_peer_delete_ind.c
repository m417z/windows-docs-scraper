NDIS_WDI_PEER_DELETE_IND NdisWdiPeerDeleteInd;

void NdisWdiPeerDeleteInd(
  [in]  NDIS_HANDLE NdisMiniportDataPathHandle,
  [in]  WDI_PORT_ID PortId,
  [in]  WDI_PEER_ID PeerId,
  [out] NDIS_STATUS *pWifiStatus
)
{...}