NDIS_WDI_PEER_CREATE_IND NdisWdiPeerCreateInd;

void NdisWdiPeerCreateInd(
  NDIS_HANDLE NdisMiniportDataPathHandle,
  WDI_PORT_ID PortId,
  WDI_PEER_ID PeerId,
  WDI_MAC_ADDRESS PeerAddr
)
{...}