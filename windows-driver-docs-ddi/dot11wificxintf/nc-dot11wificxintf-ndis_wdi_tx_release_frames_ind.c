NDIS_WDI_TX_RELEASE_FRAMES_IND NdisWdiTxReleaseFramesInd;

void NdisWdiTxReleaseFramesInd(
  NDIS_HANDLE NdisMiniportDataPathHandle,
  WDI_PORT_ID PortId,
  WDI_PEER_ID PeerId,
  UINT32 ExTidBitmask,
  UINT8 MaxNumFrames,
  UINT16 Credit,
  PNET_BUFFER_LIST *ppNBL
)
{...}