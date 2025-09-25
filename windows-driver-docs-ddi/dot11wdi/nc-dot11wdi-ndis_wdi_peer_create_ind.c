NDIS_WDI_PEER_CREATE_IND NdisWdiPeerCreateInd;

void NdisWdiPeerCreateInd(
  [in] NDIS_HANDLE NdisMiniportDataPathHandle,
  [in] WDI_PORT_ID PortId,
  [in] WDI_PEER_ID PeerId,
  [in] WDI_MAC_ADDRESS PeerAddr
)
{...}