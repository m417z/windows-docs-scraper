NDIS_WDI_TX_INJECT_FRAME_IND NdisWdiTxInjectFrameInd;

void NdisWdiTxInjectFrameInd(
  NDIS_HANDLE NdisMiniportDataPathHandle,
  WDI_PORT_ID PortId,
  WDI_PEER_ID PeerId,
  WDI_EXTENDED_TID ExTid,
  PNET_BUFFER_LIST pNBL,
  BOOLEAN bIsUnicast,
  BOOLEAN bUseLegacyRates,
  UINT16 Ethertype,
  WDI_EXEMPTION_ACTION_TYPE ExemptionAction
)
{...}