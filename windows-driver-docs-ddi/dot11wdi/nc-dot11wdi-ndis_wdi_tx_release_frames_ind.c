NDIS_WDI_TX_RELEASE_FRAMES_IND NdisWdiTxReleaseFramesInd;

void NdisWdiTxReleaseFramesInd(
  [in]  NDIS_HANDLE NdisMiniportDataPathHandle,
  [in]  WDI_PORT_ID PortId,
  [in]  WDI_PEER_ID PeerId,
  [in]  UINT32 ExTidBitmask,
  [in]  UINT8 MaxNumFrames,
  [in]  UINT16 Credit,
  [out] PNET_BUFFER_LIST *ppNBL
)
{...}