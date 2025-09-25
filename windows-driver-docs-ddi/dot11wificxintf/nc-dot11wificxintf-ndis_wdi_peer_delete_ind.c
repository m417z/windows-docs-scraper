NDIS_WDI_PEER_DELETE_IND NdisWdiPeerDeleteInd;

void NdisWdiPeerDeleteInd(
  NDIS_HANDLE NdisMiniportDataPathHandle,
  WDI_PORT_ID PortId,
  WDI_PEER_ID PeerId,
  NDIS_STATUS *pWifiStatus
)
{...}